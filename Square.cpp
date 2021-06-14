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

void Square::squarePressed(int& count)
{
    this->press = true;
}

bool Square::getIsMine()
{
    return this->isMine;
}
