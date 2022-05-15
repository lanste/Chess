//
// Created by teodor on 15.05.22.
//

#pragma once

#include "Menu.h"
#include "../../Commands/BackCmd.h"
#include "../SaveManager.h"

#include <vector>

class LoadGameMenu : public Menu
{
    public:
        LoadGameMenu(const std::shared_ptr<Interface> & ui);
        int Show() override;
        int ExecCommand(const std::string & command) override;
    protected:
        void createHeader();
        void createContent();
        void createPrompt();
        void emptyLine();

        std::shared_ptr<Interface> interface;
        std::map<std::string, std::shared_ptr<Command>> commands;

        SaveManager saves;
        std::vector<std::string> saveList;
        std::string header;
};


