/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "UI/UIManager.h"
#include "UI/ITerminal.h"
#include "Game.h"


/**
 * Represent game mainMenu
 * allows player to start new, load, (continue?) a game, or exit the application
 */
class MainMenu
{
    public:
        MainMenu();
        int Show(const std::unique_ptr<UIManager> & interface);
    protected:

};


