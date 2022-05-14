//
// Created by teodor on 14.05.22.
//

#pragma once

#include "../../UI/Interface.h"
#include "../../UI/ITerminal.h"
#include "../../Commands/Command.h"

#include <string>
#include <map>

/**
 * Abstract class representing menu
 * Not used for polymorphism, only enforces menu interface
 */
class Menu
{
    public:
        Menu() = default;
        virtual int Show() = 0;
        virtual int ExecCommand(const std::string & command) = 0;
    protected:

        std::shared_ptr<Interface> interface;
        std::string header;
        std::map<std::string, std::shared_ptr<Command>> commands; // every menu should have at least the "back" command
};