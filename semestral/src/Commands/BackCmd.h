//
// Created by teodor on 13.05.22.
//

#pragma once

#include "Command.h" // base class

/**
 * To make stuff polymorphic
 */
class BackCmd : public Command
{
    public:
        BackCmd() = default;
        int Execute() override;
    protected:
};


