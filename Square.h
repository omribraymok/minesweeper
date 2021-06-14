// Copyright Omri Braymok 2021

#pragma once

#include <iostream>

using namespace std;

class Square
{
private:
    bool press = false;
protected:
    bool isMine;
public:
    Square();
    bool getIsMine();
    int near_mine = 0;
    virtual void display();
    virtual void squarePressed(int& count);
};