//
// Created by teodor on 12.05.22.
//

#pragma once

#include "Command.h" // base class

#include "../Game.h"
#include "../Menus/StartGameMenu.h"

class MenuStartOptionCmd : public Command
{
    public:
        MenuStartOptionCmd(const std::shared_ptr<Interface> & ui);
        int Execute();
    protected:
        std::shared_ptr<Interface> interface;
};


