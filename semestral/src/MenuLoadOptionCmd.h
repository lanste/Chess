//
// Created by teodor on 12.05.22.
//

#pragma once

#include "Command.h" // base class

#include "LoadGameMenu.h"

class MenuLoadOptionCmd : public Command
{
    public:
        MenuLoadOptionCmd(const std::shared_ptr<Interface> & ui);
        int Execute();
    protected:
        std::shared_ptr<Interface> interface;
};
