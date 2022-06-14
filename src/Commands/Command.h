//
// Created by teodor on 12.05.22.
//

#pragma once

#include "../UI/Interface.h"
#include "../UI/ITerminal.h"

#include <memory>

class Command
{
    public:
        Command() = default;
        virtual int Execute() = 0;
    protected:
        std::shared_ptr<Interface> interface;
};