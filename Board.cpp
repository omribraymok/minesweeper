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
    mine_count = 0;
}

void Board::boardSetup()
{
    int rand_num;

    srand(time(0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            rand_num = rand() % 8;
            if ((0 <= rand_num && rand_num <= 2) && mine_count < N)
            {
                board[i][j] = new Mine;
                mine_count++;
            }
            else
            {
                board[i][j] = new Square;
            }
        }
    }
    countNearMine();
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
            board[i][j]->near_mine = count;
        }
    }
}
