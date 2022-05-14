/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once


#include "Menu.h"
#include "../../Commands/MainMenu/StartGameCmd.h"
#include "../../Commands/MainMenu/LoadGameCmd.h"
#include "../../Commands/MainMenu/ExitCmd.h"

#include <vector>
#include <map>
#include <string>


/**
 * Represent game mainMenu
 * allows player to start new, load, (continue?) a game, or exit the application
 */
class MainMenu : public Menu
{
    public:
        MainMenu(const std::shared_ptr<UIManager> & ui);
        int Show();
        int ExecCommand(const std::string & command);
    protected:
        void emptyLine() const{
            interface->Display("\n" + std::string( 20, ' ' ));
        }
        void createHeader() const;
        void createOptions() const;
        void createPrompt();

        std::shared_ptr<UIManager> interface;
        std::map<std::string, std::shared_ptr<Command>> commands;
        std::string header;
        std::vector<std::string> menuOptions;
};

