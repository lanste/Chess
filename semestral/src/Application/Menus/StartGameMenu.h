//
// Created by teodor on 12.05.22.
//

#pragma once

#include "Menu.h"
#include "../../UI/UIManager.h"
#include "../../UI/ITerminal.h"
#include "../../Commands/Command.h"
#include "../../Commands/ChooseGameMenu/PlayChessCmd.h"
#include "../../Commands/ChooseGameMenu/StartGameBackCmd.h"
#include "../../Commands/ChooseGameMenu/ComingSoonCmd.h"
#include "../Game.h"


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
        void createHeader();
        void createContent();
        void createPrompt();
        void emptyLine() const{
            interface->Display("\n" + std::string( 20, ' ' ));
        }

        std::shared_ptr<UIManager> interface;
        std::string header;
        std::map<std::string, std::shared_ptr<Command>> commands;
        std::vector<std::pair<std::string, std::shared_ptr<Board>>> options; // vector<string, board>
};


