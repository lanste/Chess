//
// Created by teodor on 12.05.22.
//

#pragma once

#include "../UI/UIManager.h"
#include "../UI/ITerminal.h"
#include "Game.h"

#include <memory>

class StartGameMenu
{
    public:
        StartGameMenu(const std::shared_ptr<UIManager> & ui, const Game & nGame);
        int Show();
        int ExecCommand(const std::string & command);
    protected:
};


