/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "UI/UIManager.h"
#include "Menu.h"
#include "Game.h"
#include "ProgramOptions.h"

#include <memory>

/**
 * Main class
 * Holds Interface, Menu and Game
 */
class Application
{
    public:
        Application(const ProgramOptions & options);
        //Application(); // placeholder
        int Run();
    protected:
        std::shared_ptr<UIManager> interface;
        std::shared_ptr<Menu> menu;
        std::shared_ptr<Game> game;
};
