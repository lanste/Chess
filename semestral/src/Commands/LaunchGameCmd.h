//
// Created by teodor on 14.05.22.
//

#pragma once

#include "Command.h"

class LaunchGameCmd : public Command
{
    public:
        LaunchGameCmd(const std::shared_ptr<Interface> & ui);
        int Execute() override;
    protected:
        std::shared_ptr<Interface> interface;
};


