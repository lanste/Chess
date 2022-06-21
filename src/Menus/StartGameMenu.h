//
// Created by teodor on 12.05.22.
//

#pragma once

#include "Menu.h" // base class

#include "../Commands/SetupGameCmd.h"
#include "../Commands/BackCmd.h"
#include "../Commands/ComingSoonCmd.h"


#include <memory>
#include <vector>
#include <map>
#include <string>
#include <sstream>

class StartGameMenu : public Menu
{
    public:
        explicit StartGameMenu(const std::shared_ptr<Interface> & ui);
        int Show() override;
        int ExecCommand(const std::string & command) override;
    protected:
        void emptyLine() const{
            interface->Display("\n" + std::string( 20, ' ' ));
        }
        void createHeader();
        void createContent();
        void createPrompt();

        std::shared_ptr<Interface> interface;
        std::string header;
        std::map<std::string, std::shared_ptr<Command>> commands;
        std::vector<std::pair<std::string, std::shared_ptr<Board>>> options; // vector<string, board>
};


