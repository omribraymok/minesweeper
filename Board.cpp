// Copyright Omri Braymok 2021

#pragma once

#include "Board.h"

Board::Board()
{
    boardSetup();
}

Board::~Board()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            delete board[i][j];
        }
    }
}

void Board::boardExpands(int row_num, int col_num)
{
    this->expandToDownRight(row_num, col_num);
    this->expandToDownLeft(row_num, col_num);
    this->expandToUpLeft(row_num, col_num);
    this->expandToUpRight(row_num, col_num);
}

void Board::boardSetup()
{
    int rand_num;

    srand(time(0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            rand_num = rand() % N*2;
            if ((0 <= rand_num && rand_num <= 2) && mine_count < N + N/2)
            {
                board[i][j] = new Mine;
                mine_count++;
            }
            else
            {
                board[i][j] = new Square(); 
            }
        }
    }
    countNearMine();
}

void Board::cleanBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            delete board[i][j];
        }
    }
    mine_count = 0;
}

void Board::countNearMine()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j]->getIsMine())
                continue;
            int count = 0;
            if (i - 1 >= 0 && j - 1 >=0)
            {
                if (board[i - 1][j - 1]->getIsMine())
                {
                    count++;
                }
            }
            if (i - 1 >= 0)
            {
                if (board[i - 1][j]->getIsMine())
                {
                    count++;
                }
            }
            if (i - 1 >= 0 && j + 1 <= N - 1)
            {
                if (board[i - 1][j + 1]->getIsMine())
                {
                    count++;
                }
            }
            if (j - 1 >= 0)
            {
                if (board[i][j - 1]->getIsMine())
                {
                    count++;
                }
            }
            if (j + 1 <= N - 1)
            {
                if (board[i][j + 1]->getIsMine())
                {
                    count++;
                }
            }
            if (i + 1 <= N - 1 && j - 1 >= 0)
            {
                if (board[i + 1][j - 1]->getIsMine())
                {
                    count++;
                }
            }
            if (i + 1 <= N - 1)
            {
                if (board[i + 1][j]->getIsMine())
                {
                    count++;
                }
            }
            if (i + 1 <= N - 1 && j + 1 <= N - 1)
            {
                if (board[i + 1][j + 1]->getIsMine())
                {
                    count++;
                }
            }
            board[i][j]->setNumNearbyMine(count);
        }
    }
}

void Board::expandToDownLeft(int row_num, int col_num)
{
    int i;
    int j;
    int row_mine;
    int col_mine;
    bool flag_stop = false;
    for (i = row_num; i < N && !flag_stop; i++)
    {
        for (j = col_num; j >= col_num - (i - row_num) && j >= 0; j--)
        {
            if (board[i][j]->getIsMine())
            {
                flag_stop = true;
                break;
            }
        }
    }
    row_mine = i;
    col_mine = j;
    flag_stop = false;
    for (i = row_num; i < row_mine && !flag_stop; i++)
    {
        for (j = col_num; j > col_mine && j >= 0; j--)
        {
            if (board[i][j]->getIsMine())
            {
                flag_stop = true;
                break;
            }
        }
    }
    row_mine = i;
    col_mine = j;
    for (i = row_num; i < row_mine; i++)
    {
        for (j = col_num; j > col_mine && j >= 0; j--)
        {
            board[i][j]->squarePressed(mine_count);
        }
    }

}

void Board::expandToDownRight(int row_num, int col_num)
{
    int i;
    int j;
    int row_mine;
    int col_mine;
    bool flag_stop = false;
    for (i = row_num; i < N && !flag_stop; i++)
    {
        for (j = col_num; j <= col_num + (i - row_num); j++)
        {
            if (board[i][j]->getIsMine())
            {
                flag_stop = true;
                break;
            }
        }
    }
    row_mine = i;
    col_mine = j;
    flag_stop = false;
    for (i = row_num; i < row_mine && !flag_stop; i++)
    {
        for (j = col_num; j < col_mine; j++)
        {
            if (board[i][j]->getIsMine())
            {
                flag_stop = true;
                break;
            }
        }
    }
    row_mine = i;
    col_mine = j;
    for (i = row_num; i < row_mine; i++)
    {
        for (j = col_num; j < col_mine; j++)
        {
            board[i][j]->squarePressed(mine_count);
        }
    }
    
}

void Board::expandToUpLeft(int row_num, int col_num)
{
    int i;
    int j;
    int row_mine;
    int col_mine;
    bool flag_stop = false;
    for (i = row_num; i >= 0 && !flag_stop; i--)
    {
        for (j = col_num; j >= col_num - (row_num - i) && j >= 0; j--)
        {
            if (board[i][j]->getIsMine())
            {
                flag_stop = true;
                break;
            }
        }
    }
    row_mine = i;
    col_mine = j;
    flag_stop = false;
    for (i = row_num; i > row_mine && !flag_stop; i--)
    {
        for (j = col_num; j > col_mine && j >= 0; j--)
        {
            if (board[i][j]->getIsMine())
            {
                flag_stop = true;
                break;
            }
        }
    }
    row_mine = i;
    col_mine = j;
    for (i = row_num; i > row_mine; i--)
    {
        for (j = col_num; j > col_mine && j >= 0; j--)
        {
            board[i][j]->squarePressed(mine_count);
        }
    }

}

void Board::expandToUpRight(int row_num, int col_num)
{
    int i;
    int j;
    int row_mine;
    int col_mine;
    bool flag_stop = false;
    for (i = row_num; i >= 0 && !flag_stop; i--)
    {
        for (j = col_num; j <= col_num + (row_num - i); j++)
        {
            if (board[i][j]->getIsMine())
            {
                flag_stop = true;
                break;
            }
        }
    }
    row_mine = i;
    col_mine = j;
    flag_stop = false;
    for (i = row_num; i > row_mine && !flag_stop; i--)
    {
        for (j = col_num; j < col_mine; j++)
        {
            if (board[i][j]->getIsMine())
            {
                flag_stop = true;
                break;
            }
        }
    }
    row_mine = i;
    col_mine = j;
    for (i = row_num; i > row_mine; i--)
    {
        for (j = col_num; j < col_mine; j++)
        {
            board[i][j]->squarePressed(mine_count);
        }
    }
}

void Board::printBoard()
{
    cout << "   ";
    for (int i = 0; i < N; i++)
        cout << i << "  ";
    cout << "\n";
    for (int i = 0; i < N; i++)
    {
        cout << i << "  ";
        for (int j = 0; j < N; j++)
        {
            board[i][j]->display();
            cout << "  ";
        }
        cout << "\n";
    }

}