/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Interface.h"
#include "MainMenu.h"
#include "Game.h"
#include "ProgramOptions.h"

#include <memory>

#define EXITCODE 9

/**
 * Main class
 * Holds Interface and MainMenu
 */
class Application
{
    public:
        Application(const ProgramOptions & options);
        int Run();
    protected:
        std::shared_ptr<Interface> interface;
        MainMenu mainMenu;
};
