//
// Created by teodor on 13.05.22.
//

#pragma once

#include "../Command.h"

class StartGameBackCmd : public Command
{
    public:
        StartGameBackCmd() = default;
        int Execute() override;
    protected:
};


