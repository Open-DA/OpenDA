//
//  Othello.cpp
//  Othello
//
//  Created by 范静涛 on 2022/4/2.
//

#include "Othello.hpp"
#include <iostream>
using namespace std;

const char OthBoard::DEFAULT_BOARD[SIZE][SIZE] = {
    //A         B         C         D         E         F         G         H
     {Color::S, Color::S, Color::S, Color::S, Color::S, Color::S, Color::S, Color::S},  //1
     {Color::S, Color::S, Color::S, Color::S, Color::S, Color::S, Color::S, Color::S},  //2
     {Color::S, Color::S, Color::S, Color::S, Color::S, Color::S, Color::S, Color::S},  //3
     {Color::S, Color::S, Color::S, Color::B, Color::W, Color::S, Color::S, Color::S},  //4
     {Color::S, Color::S, Color::S, Color::W, Color::B, Color::S, Color::S, Color::S},  //5
     {Color::S, Color::S, Color::S, Color::S, Color::S, Color::S, Color::S, Color::S},  //6
     {Color::S, Color::S, Color::S, Color::S, Color::S, Color::S, Color::S, Color::S},  //7
     {Color::S, Color::S, Color::S, Color::S, Color::S, Color::S, Color::S, Color::S}   //8
};

OthBoard::OthBoard(){
    Init();
}

OthBoard::OthBoard(const OthBoard& Source){
    //copy
    for (unsigned int Row = 0; Row < SIZE; Row++) {
        for (unsigned int Col = 0; Col < SIZE; Col++) {
            Board[Row][Col] = Source.Board[Row][Col];
        }
    }
}

OthBoard& OthBoard::operator=(const OthBoard& Source){
    if (this != &Source) {
        //copy
        for (unsigned int Row = 0; Row < SIZE; Row++) {
            for (unsigned int Col = 0; Col < SIZE; Col++) {
                Board[Row][Col] = Source.Board[Row][Col];
            }
        }
    }
    return *this;
}

OthBoard::~OthBoard(){
}

void OthBoard::Init(){
    //copy from default board
    for (unsigned int Row = 0; Row < SIZE; Row++) {
        for (unsigned int Col = 0; Col < SIZE; Col++) {
            Board[Row][Col] = DEFAULT_BOARD[Row][Col];
        }
    }
}

void OthBoard::Print() const{
    cout << "  A B C D E F G H\n";
    for (unsigned int Row = 0; Row < SIZE; Row++) {
        cout << " +-+-+-+-+-+-+-+-+\n" << Row + 1 << '|' ;
        for (unsigned int Col = 0; Col < SIZE; Col++) {
            cout << STATUS[Board[Row][Col]] << '|';
        }
        cout << '\n';
    }
    cout << " +-+-+-+-+-+-+-+-+\n" << endl;
}

int OthBoard::GetCurrentRow(RowNo RowBase, Direction Dir, int Step) {
    return RowBase + NBHS[Dir].RowOffset * Step;
}

int OthBoard::GetCurrentCol(ColNo ColBase, Direction Dir, int Step) {
    return ColBase + NBHS[Dir].ColOffset * Step;
}

//Get whether or not you can flip in a certain direction, without counting the number of flips
bool OthBoard::AnyDrctnlFlips(RowNo Row, ColNo Col, Direction Dir, Color Side) const{
    char OwnSide = Side;
    char OppSide = 1 - OwnSide;
    unsigned int FlipCount  = 0;
    
    //only can put a piece into a space
    if (Board[Row][Col] != Color::S) {
        return false;
    }
    
    //search for a continued oppside serial
    int Step = 1;
    while (GetCurrentRow(Row, Dir, Step) < SIZE //先判断位置后颜色，绝对不能反，否则可能越界
        && GetCurrentCol(Col, Dir, Step) < SIZE
        && Board[GetCurrentRow(Row, Dir, Step)][GetCurrentCol(Col, Dir, Step)] == OppSide){
        //add one oppside count
        FlipCount++;
        //to search next position
        Step++;
    }//end while
    
    //afer an oppside serial, is an own side piece
    if (   GetCurrentRow(Row, Dir, Step) < SIZE //先判断位置后颜色，绝对不能反，否则可能越界
        && GetCurrentCol(Col, Dir, Step) < SIZE
        && Board[GetCurrentRow(Row, Dir, Step)][GetCurrentCol(Col, Dir, Step)] == OwnSide){
        return true;
    }
    else {
        return false;
    }
}
//Get the number of pieces that can be flipped in a certain direction, when you put own piece into the specified position
unsigned int OthBoard::CountDrctnlFlips(RowNo Row, ColNo Col, Direction Dir, Color Side) const{
    char OwnSide = Side;
    char OppSide = 1 - OwnSide;
    unsigned int FlipCount  = 0;
    
    //only can put a piece into a space
    if (Board[Row][Col] != Color::S) {
        return FlipCount;
    }
    
    //search for a continued oppside serial
    int Step = 1;
    while (GetCurrentRow(Row, Dir, Step) < SIZE //先判断位置后颜色，绝对不能反，否则可能越界
        && GetCurrentCol(Col, Dir, Step) < SIZE
        && Board[GetCurrentRow(Row, Dir, Step)][GetCurrentCol(Col, Dir, Step)] == OppSide){
        //add one oppside count
        FlipCount++;
        //add step to search next position
        Step++;
    }//end while
    
    //afer an oppside serial, is an own side piece
    if (   GetCurrentRow(Row, Dir, Step) < SIZE //先判断位置后颜色，绝对不能反，否则可能越界
        && GetCurrentCol(Col, Dir, Step) < SIZE
        && Board[GetCurrentRow(Row, Dir, Step)][GetCurrentCol(Col, Dir, Step)] == OwnSide){
        return FlipCount;
    }
    else {
        return 0;
    }
}
//Get whether or not you can flip, without counting the number of flips
bool OthBoard::AnyFlips(RowNo Row, ColNo Col, Color Side) const{
    unsigned int TotalFlipCount = 0;
    for (auto e : DIRS) {
        TotalFlipCount += CountDrctnlFlips(Row, Col, e, Side);
    }
    if (TotalFlipCount > 0) {
        return true;
    }
    else {
        return false;
    }
}

//Get the number of pieces that can be flipped, when you put own piece into the specified position
unsigned int OthBoard::CountFlips(RowNo Row, ColNo Col, Color Side) const{
    unsigned int TotalFlipCount = 0;
    for (auto e : DIRS) {
        TotalFlipCount += CountDrctnlFlips(Row, Col, e, Side);
    }
    if (TotalFlipCount > 0) {
        return TotalFlipCount;
    }
    else {
        return 0;
    }

}

//Flip and return counts
unsigned int OthBoard::DoFlips(RowNo Row, ColNo Col, Color Side){
    unsigned int TotalFlipCount = 0;
    //Flip to each direction
    for (auto e : DIRS) {
        //flip count of this direction
        unsigned int FlipCount = CountDrctnlFlips(Row, Col, e, Side);
        TotalFlipCount += FlipCount;
        for (int Step = 1; Step <= FlipCount; Step++) {
            Board[GetCurrentRow(Row, e, Step)][GetCurrentCol(Col, e, Step)] = Side;
        }
    }
    if (TotalFlipCount > 0) {
        Board[Row][Col] = Side;
        return TotalFlipCount;
    }
    else {
        return 0;
    }
}

