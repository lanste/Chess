//
// Created by teodor on 12.05.22.
//

#pragma once

#include "Command.h"
#include "StartGameCmd.h"
#include "LoadGameCmd.h"
#include "ExitCmd.h"

#include <map>
#include <string>
#include <memory>


/**
 * Processes input received from user via active interface
 * Manages execution of individual commands
 */
class CommandManager
{
    public:
        CommandManager();
        int Execute(std::string command);
    protected:
        std::map<std::string, std::shared_ptr<Command>> commands;

};


