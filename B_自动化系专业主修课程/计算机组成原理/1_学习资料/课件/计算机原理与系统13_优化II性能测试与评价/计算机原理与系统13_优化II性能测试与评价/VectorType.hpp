//
//  VectorType.hpp
//
//  Created by 范静涛 on 2022/4/6.
//

#ifndef VectorType_hpp
#define VectorType_hpp

#include <cstddef>
#include <ctime>
#include <string>
#include <map>

using namespace std;

template<typename data_t>
class Vec{
public:
    Vec(size_t Length);
    Vec(const Vec& Source);
    Vec& operator=(const Vec& Source);
    ~Vec();
    size_t GetLength() const;
    bool GetElement(size_t Idx, data_t* Dst) const;
    bool SetElement(size_t Idx, data_t  Val);
    void Reduce_Ver1(data_t* Dst, const string& Op);
    void Reduce_Ver2(data_t* Dst, const string& Op);
    void Reduce_Ver3(data_t* Dst, const string& Op);
    void Reduce_Ver4(data_t* Dst, const string& Op);
    void Reduce_Ver5(data_t* Dst, const string& Op);
    void Reduce_Ver6(data_t* Dst, const string& Op);
    void Reduce_Ver7(data_t* Dst, const string& Op);
    void Reduce_Ver8(data_t* Dst, const string& Op);
private:
    data_t* GetStart() const;
    size_t Len;
    data_t* Data;
    //Reduce Idents
    map<string, data_t> Ident{
        {"+", 0},
        {"*", 1}
    };
    //Reduce Functions
    map<string, function<data_t(data_t, data_t)> > Operators{
        {"+", [](data_t x, data_t y) {
                return x + y;
              }
        },
        {"*", [](data_t x, data_t y) {
                return x * y;
              }
        }
    };
};

template<typename data_t>
Vec<data_t>::Vec(size_t Length){
    Len = Length;
    if (Len > 0) {
        Data = new data_t[Len];
        for(size_t i = 0 ; i < Len; i++) {
            Data[i] = rand() / 100;
        }
    }
    else {
        Data = nullptr;
    }
}

template<typename data_t>
Vec<data_t>::Vec(const Vec& Source){
    Len = Source.Len;
    if (Len > 0) {
        Data = new data_t[Len];
        for(size_t i = 0 ; i < Len; i++) {
            Data[i] = Source.Data[i];
        }
    }
    else {
        Data = nullptr;
    }
}

template<typename data_t>
Vec<data_t>& Vec<data_t>::operator=(const Vec& Source){
    if (&Source != this) {
        if (Len > 0) {
            delete[] Data;
        }
        Len = Source.Len;
        if (Len > 0) {
            Data = new data_t[Len];
            for(size_t i = 0 ; i < Len; i++) {
                Data[i] = Source.Data[i];
            }
        }
        else {
            Data = nullptr;
        }
    }
    return *this;
}

template<typename data_t>
Vec<data_t>::~Vec(){
    if (Len > 0) {
        delete[] Data;
    }
}

template<typename data_t>
inline size_t Vec<data_t>::GetLength() const{
    return Len;
}

template<typename data_t>
bool Vec<data_t>::GetElement(size_t Idx, data_t* Dst) const{
    if (Idx < Len) {
        *Dst = Data[Idx];
        return true;
    }
    else {
        return false;
    }
    //return (Idx < Len)?((*Dst = Data[Idx]), true) : (false);
}

template<typename data_t>
bool Vec<data_t>::SetElement(size_t Idx, data_t Val) {
    if (Idx < Len) {
        Data[Idx] = Val;
        return true;
    }
    else {
        return false;
    }
}

template<typename data_t>
data_t* Vec<data_t>::GetStart() const {
    return Data;
}

template<typename data_t>
void Vec<data_t>::Reduce_Ver1(data_t* Dst, const string& Op){
    *Dst = Ident[Op];
    for (size_t i = 0; i < GetLength(); i++) {
        data_t Val;
        GetElement(i, &Val);
        *Dst = Operators[Op](*Dst, Val);
    }
}

template<typename data_t>
void Vec<data_t>::Reduce_Ver2(data_t* Dst, const string& Op){
    *Dst = Ident[Op];
    auto op = Operators[Op];
    for (size_t i = 0; i < Len; i++) {
        data_t Val;
        GetElement(i, &Val);
        *Dst = op(*Dst, Val);
    }
}

template<typename data_t>
void Vec<data_t>::Reduce_Ver3(data_t* Dst, const string& Op){
    *Dst = Ident[Op];
    auto op = Operators[Op];
    for (size_t i = 0; i < Len; i++) {
        *Dst = op(*Dst, Data[i]);
    }
}

template<typename data_t>
void Vec<data_t>::Reduce_Ver4(data_t* Dst, const string& Op){
    data_t Acc = Ident[Op];
    auto op = Operators[Op];
    for (size_t i = 0; i < Len; i++) {
        Acc = op(Acc, Data[i]);
    }
    *Dst = Acc;
}

template<typename data_t>
void Vec<data_t>::Reduce_Ver5(data_t* Dst, const string& Op){
    size_t STEP = 3;
    size_t i;
    size_t Limit = Len - STEP + 1;
    data_t Acc = Ident[Op];
    auto op = Operators[Op];
    for (i = 0; i < Limit; i += STEP) {
        Acc = op(op(op(Acc, Data[i]), Data[i + 1]), Data[i + 2]);
    }
    for (; i < Len; i++) {
        Acc = op(Acc, Data[i]);
    }
    *Dst = Acc;
}

template<typename data_t>
void Vec<data_t>::Reduce_Ver6(data_t* Dst, const string& Op){
    size_t i;
    size_t STEP = 3;
    size_t Limit = Len - STEP + 1;
    data_t Acc0 = Ident[Op];
    data_t Acc1 = Ident[Op];
    data_t Acc2 = Ident[Op];
    auto op = Operators[Op];
    for (i = 0; i < Limit; i += STEP) {
        Acc0 = op(Acc0, Data[i]);
        Acc1 = op(Acc1, Data[i + 1]);
        Acc2 = op(Acc2, Data[i + 2]);
    }
    for (; i < Len; i++) {
        Acc0 = op(Acc0, Data[i]);
    }
    *Dst = op(op(Acc0, Acc1), Acc2);
}


template<typename data_t>
void Vec<data_t>::Reduce_Ver7(data_t* Dst, const string& Op){
    
}


template<typename data_t>
void Vec<data_t>::Reduce_Ver8(data_t* Dst, const string& Op){
    
}


#endif /* VectorType_hpp */
