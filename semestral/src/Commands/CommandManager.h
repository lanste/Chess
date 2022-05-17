//
// Created by teodor on 12.05.22.
//

#pragma once

#include "Command.h"
#include "MainMenu/MenuStartOptionCmd.h"
#include "MainMenu/MenuLoadOptionCmd.h"
#include "MainMenu/ExitCmd.h"

#include <map>
#include <string>
#include <memory>


/**
 * Processes input received from user via active interface
 * Manages execution of individual commands
 * Deprecated
 */
class CommandManager
{
    public:
        CommandManager();
        int Execute(const std::string & command, const std::string & calledFrom);
    protected:
        std::map<std::string, std::shared_ptr<Command>> menuCommands;

};


