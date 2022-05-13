//
// Created by teodor on 12.05.22.
//

#pragma once

#include "../UI/UIManager.h"
#include "../UI/ITerminal.h"
#include "../Commands/Command.h"
#include "../Commands/ChooseGameMenu/PlayChessCmd.h"
#include "../Commands/ChooseGameMenu/PlayChessCmd.cpp"
#include "../Commands/ChooseGameMenu/StartGameBackCmd.h"
#include "../Commands/ChooseGameMenu/StartGameBackCmd.cpp"
#include "../Commands/ChooseGameMenu/ComingSoonCmd.h"
#include "../Commands/ChooseGameMenu/ComingSoonCmd.cpp"
#include "Game.h"


#include <memory>
#include <vector>
#include <map>
#include <string>
#include <sstream>

class StartGameMenu
{
    public:
        StartGameMenu(const std::shared_ptr<UIManager> & ui, const Game & nGame);
        int Show();
        int ExecCommand(const std::string & command);
    protected:
        void createHeader();
        void createContent();
        void createPrompt();
        void emptyLine() const{
            interface->Display("\n" + std::string( 20, ' ' ));
        }

        Game game;
        std::map<std::string, std::shared_ptr<Command>> commands;
        std::shared_ptr<UIManager> interface;
        std::string header;
        std::vector<std::pair<std::string, std::shared_ptr<Board>>> options; // vector<string, board>
};


