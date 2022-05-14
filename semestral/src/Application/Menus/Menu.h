//
// Created by teodor on 14.05.22.
//

#pragma once

#include <string>

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
};