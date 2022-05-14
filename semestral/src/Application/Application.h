/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "../UI/UIManager.h"
#include "Menus/MainMenu.h"
#include "Game.h"
#include "ProgramOptions.h"
//#include "../Commands/CommandManager.h"

#include <memory>

#define EXITCODE 9
/**
 * Main class
 * Holds Interface, MainMenu and Game
 */
class Application
{
    public:
        Application(const ProgramOptions & options);
        //Application(); // placeholder
        int Run();
    protected:
        std::shared_ptr<UIManager> interface;
        std::unique_ptr<MainMenu> mainMenu;
        //CommandManager cmdManager;
        Game game;
};
