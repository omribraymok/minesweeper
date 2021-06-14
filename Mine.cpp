// Copyright Omri Braymok 2021

#pragma once

#include "Mine.h"

Mine::Mine()
{
    this->isMine = true;
}

void Mine::display()
{
    if (this->press)
        cout << "@";

    else
        cout << "*";
}

void Mine::squarePressed(int& count)
{
    this->press = true;
    count--;
}
