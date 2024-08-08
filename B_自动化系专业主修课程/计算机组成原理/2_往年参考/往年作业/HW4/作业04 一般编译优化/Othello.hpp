//
//  Othello.hpp
//  Othello
//
//  Created by 范静涛 on 2022/4/2.
//

#ifndef Othello_hpp
#define Othello_hpp

//Color: black, white, space(no piece)
class ColorEnum {
public:
    enum Type{
        B = 0, //Black
        W = 1, //White
        S = 2  //Space
    };
private:
    //This class is not instantiatable
    virtual void NoInstance() = 0;
};
using Color = ColorEnum::Type;

//Directions for search
class DirEnum{
public:
    enum Type{
        LEFT       = 0,
        LEFT_UP    = 1,
        UP         = 2,
        RIGHT_UP   = 3,
        RIGHT      = 4,
        RIGHT_DOWN = 5,
        DOWN       = 6,
        LEFT_DOWN  = 7
    };
private:
    //This class is not instantiatable
    virtual void NoInstance() = 0;
};
using Direction = DirEnum::Type;

//Row Number for R1 to R8
class RowNoEnum{
public:
    enum Type{
        R1 = 0,
        R2 = 1,
        R3 = 2,
        R4 = 3,
        R5 = 4,
        R6 = 5,
        R7 = 6,
        R8 = 7
    };
private:
    //This class is not instantiatable
    virtual void NoInstance() = 0;
};
using RowNo = RowNoEnum::Type;

//Column number from A to H
class ColNoEnum{
public:
    enum Type{
        A = 0,
        B = 1,
        C = 2,
        D = 3,
        E = 4,
        F = 5,
        G = 6,
        H = 7
    };
private:
    //This class is not instantiatable
    virtual void NoInstance() = 0;
};
using ColNo = ColNoEnum::Type;

//Row and Col offsets for neighborhood in the board
using Neighborhood = struct {
    int RowOffset;
    int ColOffset;
};

//Class for Othello games
class OthBoard{
public:
    //Default Constructor
    OthBoard();
    //Copy Constructor
    OthBoard(const OthBoard& Source);
    //Operator Assignment
    OthBoard& operator=(const OthBoard& Source);
    //Virtual destructor
    virtual ~OthBoard();
    
    //........
    //........
    //........
    //...BW...
    //...WB...
    //........
    //........
    //........
    void Init();
    //Print currnet board with pieces
    void Print() const;
    //Get whether or not you can flip in a certain direction, without counting the number of flips
    bool AnyDrctnlFlips(RowNo Row, ColNo Col, Direction Dir, Color Side) const;
    //Get the number of pieces that can be flipped in one direction, when you put own piece into the specified position
    unsigned int CountDrctnlFlips(RowNo Row, ColNo Col, Direction Dir, Color Side) const;
    //Get whether or not you can flip, without counting the number of flips
    bool AnyFlips(RowNo Row, ColNo Col, Color Side) const;
    //Get the number of pieces that can be flipped, when you put own piece into the specified position
    unsigned int CountFlips(RowNo Row, ColNo Col, Color Side) const;
    //Flip and return counts
    unsigned int DoFlips(RowNo Row, ColNo Col, Color Side);
protected:
    //Board Size 8 by 8
    constexpr static const int  SIZE = 8;
    //char for print: black, white, space
    constexpr static const char STATUS[3]={'B','W',' '};
    //enum array for convert from int to row number
    constexpr static const RowNo ROWS[] = {RowNo::R1, RowNo::R2, RowNo::R3, RowNo::R4, RowNo::R5, RowNo::R6, RowNo::R7, RowNo::R8};
    //enum array for convert from int to column number
    constexpr static const ColNo COLS[] = {ColNo::A,  ColNo::B,  ColNo::C,  ColNo::D,  ColNo::E,  ColNo::F,  ColNo::G,  ColNo::H};
    //enum array for convert from int to search direction
    constexpr static const Direction DIRS[] = {Direction::LEFT, Direction::LEFT_UP, Direction::UP,Direction::RIGHT_UP, Direction::RIGHT, Direction::RIGHT_DOWN, Direction::DOWN, Direction::LEFT_DOWN};
    //array of row and column offsets for search by direction
    constexpr static const Neighborhood NBHS[8] = {
        {.RowOffset =  0, .ColOffset = -1},  //←
        {.RowOffset = -1, .ColOffset = -1},  //↖
        {.RowOffset = -1, .ColOffset =  0},  //↑
        {.RowOffset = -1, .ColOffset =  1},  //↗
        {.RowOffset =  0, .ColOffset =  1},  //→
        {.RowOffset =  1, .ColOffset =  1},  //↘
        {.RowOffset =  1, .ColOffset =  0},  //↓
        {.RowOffset =  1, .ColOffset = -1}   //↙
    };
    static int GetCurrentRow(RowNo RowBase, Direction Dir, int Step);
    static int GetCurrentCol(ColNo ColBase, Direction Dir, int Step);
private:
    //default board
    //........
    //........
    //........
    //...BW...
    //...WB...
    //........
    //........
    //........
    static const char DEFAULT_BOARD[SIZE][SIZE];
    char Board[SIZE][SIZE];
};

#endif /* Othello_hpp */
