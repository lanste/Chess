//
// Created by teodor on 12.05.22.
//

#pragma once

#include "../Command.h"
#include "../../Application/Game.h"
#include "../../Application/StartGameMenu.h"

class StartGameCmd : public Command
{
    public:
        StartGameCmd(const Game & nGame, const std::shared_ptr<UIManager> & ui);
        int Execute();
    protected:
        Game game;
        std::shared_ptr<UIManager> interface;
};


