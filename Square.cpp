// Copyright Omri Braymok 2021

#pragma once

#include "Square.h"

Square::Square()
{
    this->isMine = false;
}

void  Square::display()
{
    if (this->press)
        cout << near_mine;

    else
        cout << "*";
}

bool Square::getIsMine()
{
    return this->isMine;
}

int Square::getNumNearbyMine()
{
    return this->near_mine;
}

void Square::setNumNearbyMine(int count)
{
    this->near_mine = count;
}

void Square::squarePressed(int& count)
{
    this->press = true;
}