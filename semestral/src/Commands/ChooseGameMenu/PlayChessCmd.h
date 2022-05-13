//
// Created by teodor on 13.05.22.
//

#pragma once

#include "../Command.h"

class PlayChessCmd : public Command
{
    public:
        PlayChessCmd();
        int Execute() override;

    protected:
};


