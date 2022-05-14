//
// Created by teodor on 13.05.22.
//

#pragma once

#include "Command.h"

class BackCmd : public Command
{
    public:
        BackCmd() = default;
        int Execute() override;
    protected:
};


