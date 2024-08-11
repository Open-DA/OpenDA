//
//  main.cpp
//
//  Created by 范静涛 on 2022/4/6.
//
#include <ctime>
#include <iostream>
#include "VectorType.hpp"

int main(int argc, char* argv[]) {
    
    const size_t Range[] = {10,    20,    30,    40,    50,
                      100,   200,   300,   400,   500,
                      1000,  2000,  3000,  4000,  5000,
                      10000, 20000, 30000, 40000, 50000};
    
    const int COUNT = 100;
    
    clock_t Start;
    clock_t Elapsed;
    clock_t Avg;
    
    Vec<int>* pVecInt;
    int Val = 0;
    
    for(auto r : Range) {
        Avg = 0;
        pVecInt = new Vec<int>(r);
        for (int i  = 0; i < COUNT; i++) {
            Val = 0;
            Start = clock();
            pVecInt->Reduce_Ver5(&Val, "+");
            Elapsed = clock() - Start;
            Avg += Elapsed;
        }
        cout << static_cast<double>(Avg) / COUNT  * (1e9 / CLOCKS_PER_SEC) * 3.3; //3.3Ghz
        cout << endl;
        delete pVecInt;
    }
    return 0;
}
