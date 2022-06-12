//
// Created by teodor on 12.05.22.
//

#pragma once

#include "Command.h" // base class

#define EXITCODE 9 //todo this is suboptimal
class ExitCmd : public Command
{
    public:
        ExitCmd() = default;
        int Execute() override {return EXITCODE;}
};


