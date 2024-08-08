//
//  Test.hpp
//  MemMountain
//
//  Created by 范静涛 on 2022/5/6.
//

#ifndef MemMtn_hpp
#define MemMtn_hpp

#include <cstddef>
#include <vector>

//data_t: element type
//BYTES_MIN: first working set size
//BYTES_MAX: last working set size
//STRIDE_MAX: last stride in 'word' == * sizeof(data_t) bytes
//            last stride is one
template <class data_t, size_t BYTES_MIN, size_t BYTES_MAX, size_t STRIDE_MAX>
class MemMountain{
public:
    static void InitData();
    static double GetBandWidth(size_t SizeInBytes, size_t Stride, double Hz);
    static std::vector<std::vector<double>> GetMap(double Hz);
private:
    constexpr static const size_t MAXELEMS = BYTES_MAX / sizeof(data_t);
    static data_t Reduce_Sum(size_t ElemCount, size_t Stride);
    //The global array we'll be traversing
    static data_t Data[MAXELEMS];
};

template <class data_t, size_t BYTES_MIN, size_t BYTES_MAX, size_t STRIDE_MAX>
data_t MemMountain<data_t, BYTES_MIN, BYTES_MAX, STRIDE_MAX>::Data[MAXELEMS];


//initializes the internal array
template <class data_t, size_t BYTES_MIN, size_t BYTES_MAX, size_t STRIDE_MAX>
void MemMountain<data_t, BYTES_MIN, BYTES_MAX, STRIDE_MAX>::InitData(){
    for (size_t i = 0; i < MAXELEMS; i++) {
        Data[i] = i;
    }
}

//Iterate over first "ElemCount" elements of array "Data"
//with stride of "Stride".
template <class data_t, size_t BYTES_MIN, size_t BYTES_MAX, size_t STRIDE_MAX>
data_t MemMountain<data_t, BYTES_MIN, BYTES_MAX, STRIDE_MAX>::Reduce_Sum(size_t ElemCount, size_t Stride){
    size_t Sx2 = Stride * 2;
    size_t Sx3 = Stride * 3;
    size_t Sx4 = Stride * 4;
    size_t Length = ElemCount;
    size_t Limit  = Length - Sx4;
    data_t acc0 = 0;
    data_t acc1 = 0;
    data_t acc2 = 0;
    data_t acc3 = 0;

    size_t i;
    //Combine 4 elements at a time
    for (i = 0; i < Limit; i += Sx4) {
        acc0 = acc0 + Data[i];
        acc1 = acc1 + Data[i + Stride];
        acc2 = acc2 + Data[i + Sx2];
        acc3 = acc3 + Data[i + Sx3];
    }
    
    //Finish any remaining elements
    for (; i < Length; i++) {
        acc0 = acc0 + Data[i];
    }
    return ((acc0 + acc1) + (acc2 + acc3));
    
}
//return xxMB/s
template <class data_t, size_t BYTES_MIN, size_t BYTES_MAX, size_t STRIDE_MAX>
double MemMountain<data_t, BYTES_MIN, BYTES_MAX, STRIDE_MAX>::GetBandWidth(size_t SizeInBytes, size_t Stride, double Hz){
    uint32_t StartHigh;
    uint32_t StartLow;
    uint32_t StopHigh;
    uint32_t StopLow;
    size_t ElemCount = SizeInBytes / sizeof(data_t);
    //warm up
    Reduce_Sum(ElemCount, Stride);
    //count
    __asm__ __volatile__ ("rdtsc" : "=a" (StartLow), "=d" (StartHigh));
    Reduce_Sum(ElemCount, Stride);
    __asm__ __volatile__ ("rdtsc" : "=a" (StopLow), "=d" (StopHigh));
    uint64_t Cycles = ((uint64_t)StopHigh << 32 | StopLow) - ((uint64_t)StartHigh << 32 | StartLow);
    //double Res = (static_cast<double>(SizeInBytes) / Stride) / (static_cast<double>(Cycles) / MHz) ;
    //MBytes = static_cast<double>(SizeInBytes) / Stride / (1<<20);
    //1.11669e+11
    //9.01943e+10
    double Res = (static_cast<double>(SizeInBytes) / Stride / (1<<20)) / (static_cast<double>(Cycles) / Hz);
    return Res;
}

template <class data_t, size_t BYTES_MIN, size_t BYTES_MAX, size_t STRIDE_MAX>
std::vector<std::vector<double>> MemMountain<data_t, BYTES_MIN, BYTES_MAX, STRIDE_MAX>::GetMap(double Hz){
    std::vector<double> LineRes;
    std::vector<std::vector<double>> Res;
    InitData();
    for (size_t Size = BYTES_MAX; Size >= BYTES_MIN; Size >>= 1) {
        LineRes.clear();
        for (size_t Stride = 1; Stride <= STRIDE_MAX; Stride += 1) {
            LineRes.push_back(GetBandWidth(Size, Stride, Hz));
        }
        Res.push_back(LineRes);
    }
    return Res;
}
#endif /* MemMtn_hpp */
