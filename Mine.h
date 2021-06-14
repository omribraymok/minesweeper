// Copyright Omri Braymok 2021

#pragma once

#include "Square.h"

class Mine : public Square
{
private:
    bool press = false;
public:
    Mine();
    void display() override;
    void squarePressed(int& count) override;
};