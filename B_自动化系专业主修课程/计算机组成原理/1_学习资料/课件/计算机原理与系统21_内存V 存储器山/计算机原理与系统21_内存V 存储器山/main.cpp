//
//  main.cpp
//  MemMountain
//
//  Created by 范静涛 on 2022/5/6.
//

#include <iostream>
#include "MemMountain.hpp"

int main(int argc, const char * argv[]) {
//    std::cout << MemMountain<long long int, 1<<14, 1<<14, 12>::GetBandWidth(1<<27, 1, 3.1 * 1024 * 1024 * 1024) << std::endl;
//    std::cout << MemMountain<long long int, 1<<14, 1<<14, 12>::GetBandWidth(1<<27, 12, 3.1 * 1024 * 1024 * 1024) << std::endl;
    std::vector<std::vector<double>> Res;
    //                               16K    128M   Stride_Max
    Res = MemMountain<long long int, 1<<14, 1<<27, 12>::GetMap(3.1 * 1024 * 1024 * 1024);
    for (auto& l : Res) {
        for (auto& e : l) {
            std::cout << e << '\t';
        }
        std::cout << std::endl;
    }
    return 0;
}
