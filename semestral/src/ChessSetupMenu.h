//
// Created by teodor on 14.05.22.
//

#pragma once

#include "Menu.h" // base class

#include "BackCmd.h"
#include "LaunchGameCmd.h"
// players might be included in ^
#include "Player.h"
#include "LocalPlayer.h"
#include "AI1.h"
#include "AI2.h"
#include "AI3.h"

#include <vector>
#include <sstream>

/**
 * Allows user to select players and potentially other game settings
 */
class ChessSetupMenu : public Menu
{
    public:
        ChessSetupMenu(const std::shared_ptr<Interface> & ui);
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

        enum{CHOOSEP1, CHOOSEP2, SETUPDONE, CONTINUE};
        std::shared_ptr<Interface> interface;
        std::vector<std::string> options;
        std::map<std::string, std::shared_ptr<Player>> pChooser;
        std::map<std::string, std::shared_ptr<Command>> commands;

        std::vector<std::shared_ptr<Player>> players; // for game initialization

        int execState;
        std::string header;
};