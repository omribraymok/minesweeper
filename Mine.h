// Copyright Omri Braymok 2021

#pragma once

#include "Square.h"

class Mine : public Square
{
private:
    bool press = false;

public:
    Mine();
    virtual ~Mine() override = default;

    virtual void display() override;
    virtual void squarePressed(int& count) override;
};