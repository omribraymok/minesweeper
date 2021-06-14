// Copyright Omri Braymok 2021

#pragma once

#include <iostream>
#include <random>
#include <time.h>
#include "Square.h"
#include "Mine.h"

using namespace std;

const int N = 4;

class Board
{
private:
public:
    int mine_count = 0;
    Square* board[N][N];
    Board();
    ~Board();
    void boardSetup();
    void printBoard();
    void countNearMine();
};
