//
// Created by teodor on 12.05.22.
//

#pragma once

#include "../Command.h"
#include "../../Application/Menus/LoadGameMenu.h"

class LoadGameCmd : public Command
{
    public:
        LoadGameCmd(const std::shared_ptr<Interface> & ui);
        int Execute();
    protected:
        std::shared_ptr<Interface> interface;
};
