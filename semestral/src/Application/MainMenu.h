/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "../UI/UIManager.h"
#include "../UI/ITerminal.h"
#include "Game.h"

#include <vector>
#include <string>

/**
 * Represent game mainMenu
 * allows player to start new, load, (continue?) a game, or exit the application
 */
class MainMenu
{
    public:
        MainMenu();
        int Show(const std::shared_ptr<UIManager> & interface);
    protected:
        std::string createHeader() const;
        std::string createOptions() const;
        std::string emptyLine() const;
        struct Dims
        {
            size_t width;
            size_t height;
        };
        std::string header;
        std::vector<std::string> menuOptions;
        std::string createPrompt();
        Dims dimensions;
};


