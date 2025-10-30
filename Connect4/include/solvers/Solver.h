#pragma once
#include "ConnectFour.h"

class Solver
{
public:
    virtual ~Solver() = default;
    virtual int chooseMove(const ConnectFour &game) = 0;
};
