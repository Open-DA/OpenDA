//
//  main.cpp
//  Othello
//
//  Created by 范静涛 on 2022/4/2.
//

#include "Othello.hpp"

int main(int argc, const char * argv[]) {
    OthBoard Board;
    Board.Print();
    Board.DoFlips(RowNo::R3, ColNo::D, Color::W);
    Board.Print();
    return 0;
}
