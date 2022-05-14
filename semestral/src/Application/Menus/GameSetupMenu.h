//
// Created by teodor on 14.05.22.
//

#pragma once

#include "Menu.h"
#include "../../Commands/ChoosePlayerCmd.h"
#include "../../Commands/BackCmd.h"
#include "../../Commands/LaunchGameCmd.h"
// players might be included in ^
#include "../../Players/Player.h"
#include "../../Players/LocalPlayer.h"
#include "../../Players/AI1.h"
#include "../../Players/AI2.h"
#include "../../Players/AI3.h"

#include <vector>
#include <sstream>

/**
 * Allows user to select players and potentially other game settings
 */
class GameSetupMenu : public Menu
{
    public:
        GameSetupMenu(const std::shared_ptr<Interface> & ui);
        int Show() override;
        int ExecCommand(const std::string & command) override;
    protected:
        void createHeader();
        void createSubHeader();
        void createContent();
        void createPrompt();
        void emptyLine() const{
            interface->Display("\n" + std::string( 20, ' ' ));
        }
        std::shared_ptr<Interface> interface;
        std::vector<std::pair<std::string, std::shared_ptr<Player>>> options;
        std::map<std::string, std::shared_ptr<Command>> commands;

        std::vector<std::shared_ptr<Player>> players; // for game initialization

        int status;
        std::string header;
};