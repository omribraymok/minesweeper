// Copyright Omri Braymok 2021

#include <iostream>
#include <string>
#include "Board.h"

using namespace std;

void displayMenu()
{
    cout << "0. Quit" << endl;
    cout << endl;
    cout << "1. Play" << endl;
    cout << endl;
    cout << "2. New Game\n" << endl;
}

void playGame(Board& board)
{
    int i, j;
    cout << "Please enter two number, between 1 to " << N << ",separated by space:" << endl;
    cin >> i >> j;
    board.board[i][j]->squarePressed(board.mine_count);
    system("cls"); //this is not a safe thing to do?
    board.printBoard();
    cout << "The remainder number of mine:" << board.mine_count << endl;
    cout << endl;
}

void newGame(Board& board)
{
    system("cls"); //this is not a safe thing to do?
    board.~Board(); //this is right thing to do?
    board.boardSetup();
    board.printBoard();
    cout << "The number of mine:" << board.mine_count << endl;
    cout << endl;
}

int main()
{
    int choice;
    Board board;

    board.printBoard();
    cout << "The number of mine:" << board.mine_count << endl;
    cout << endl;

    while (true)
    {
        displayMenu();
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Good Bye" << endl;
            return 0;
        case 1:
            playGame(board);
            break;
        case 2:
            newGame(board);
            break;
        }
    }

    return 0;
}