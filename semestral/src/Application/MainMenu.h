/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once


#include "../Commands/Command.h"
#include "../Commands/MainMenu/StartGameCmd.h"
#include "../Commands/MainMenu/LoadGameCmd.h"
#include "../Commands/MainMenu/ExitCmd.h"
#include "../UI/UIManager.h"
#include "../UI/ITerminal.h"
#include "Game.h"

#include <vector>
#include <map>
#include <string>


/**
 * Represent game mainMenu
 * allows player to start new, load, (continue?) a game, or exit the application
 */
class MainMenu
{
    public:
        MainMenu(const std::shared_ptr<UIManager> & ui, const Game & nGame);
        int Show();
        int ExecCommand(const std::string & command);
    protected:
        [[nodiscard]] std::string createHeader() const;
        [[nodiscard]] std::string createOptions() const;
        [[nodiscard]] std::string emptyLine() const;
        struct Dims
        {
            size_t width;
            size_t height;
        };
        std::shared_ptr<UIManager> interface;
        Game game;

        std::map<std::string, std::shared_ptr<Command>> commands;
        std::string header;
        std::vector<std::string> menuOptions;
        std::string createPrompt();
        Dims dimensions;
};


