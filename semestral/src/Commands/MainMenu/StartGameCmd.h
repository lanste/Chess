//
// Created by teodor on 12.05.22.
//

#pragma once

#include "../Command.h"
#include "../../Application/Game.h"
#include "../../Application/Menus/StartGameMenu.h"

class StartGameCmd : public Command
{
    public:
        StartGameCmd(const std::shared_ptr<UIManager> & ui);
        int Execute();
    protected:
        std::shared_ptr<UIManager> interface;
};


