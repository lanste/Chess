//
// Created by teodor on 14.05.22.
//

#pragma once

#include "Command.h"


class ChoosePlayerCmd : public Command
{
    public:
        ChoosePlayerCmd() = default;
        int Execute() override;
};


