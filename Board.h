// Copyright Omri Braymok 2021

#pragma once

#include <iostream>
#include <random>
#include <time.h>
#include "Square.h"
#include "Mine.h"

using namespace std;

const int N = 8;

struct RowColExpands
{
    int row;
    int col;
};

class Board
{
private:
public:
    Board();
    ~Board();

    int mine_count = 0;
    Square* board[N][N];

    void boardExpands(int row_num, int col_num);
    void boardSetup();
    void cleanBoard();
    void countNearMine();
    void expandToDownLeft(int row_num, int col_num);
    void expandToDownRight(int row_num, int col_num);
    void expandToUpLeft(int row_num, int col_num);
    void expandToUpRight(int row_num, int col_num);
    void printBoard();
};
