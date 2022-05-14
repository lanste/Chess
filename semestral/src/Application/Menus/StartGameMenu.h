//
// Created by teodor on 12.05.22.
//

#pragma once

#include "Menu.h"
#include "../../Commands/ChooseGameMenu/SetupGameCmd.h"
#include "../../Commands/BackCmd.h"
#include "../../Commands/ChooseGameMenu/ComingSoonCmd.h"


#include <memory>
#include <vector>
#include <map>
#include <string>
#include <sstream>

class StartGameMenu : public Menu
{
    public:
        StartGameMenu(const std::shared_ptr<UIManager> & ui);
        int Show();
        int ExecCommand(const std::string & command);
    protected:
        void emptyLine() const{
            interface->Display("\n" + std::string( 20, ' ' ));
        }
        void createHeader();
        void createContent();
        void createPrompt();

        std::shared_ptr<UIManager> interface;
        std::string header;
        std::map<std::string, std::shared_ptr<Command>> commands;
        std::vector<std::pair<std::string, std::shared_ptr<Board>>> options; // vector<string, board>
};


