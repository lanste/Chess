//
// Created by teodor on 13.05.22.
//

#pragma once

#include "../Command.h"

class ComingSoonCmd : public Command
{
    public:
        ComingSoonCmd();
        int Execute() override;
    protected:
};