// Copyright Omri Braymok 2021

#pragma once

#include <iostream>

using namespace std;

class Square
{
private:
    bool press = false;
    int near_mine = 0;

protected:
    bool isMine;

public:
    Square();
    virtual ~Square() = default;

    virtual void display();
    bool getIsMine();
    int getNumNearbyMine();
    void setNumNearbyMine(int x);
    virtual void squarePressed(int& count);
};