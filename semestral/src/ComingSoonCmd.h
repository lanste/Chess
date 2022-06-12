//
// Created by teodor on 13.05.22.
//

#pragma once

#include "Command.h" // base class

#include "Interface.h"
#include "ITerminal.h"

#include <memory>

class ComingSoonCmd : public Command
{
    public:
        ComingSoonCmd(const std::shared_ptr<Interface> & ui);
        int Execute() override;
    protected:
        std::shared_ptr<Interface> interface;
};