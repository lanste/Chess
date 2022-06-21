//
// Created by teodor on 13.05.22.
//

#pragma once

#include "Command.h" // base class

#include "../UI/Interface.h"
#include "../UI/ITerminal.h"

#include <memory>

class ComingSoonCmd : public Command
{
    public:
        explicit ComingSoonCmd(const std::shared_ptr<Interface> & ui);
        int Execute() override;
    protected:
        std::shared_ptr<Interface> interface;
};