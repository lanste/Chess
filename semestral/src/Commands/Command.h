//
// Created by teodor on 12.05.22.
//

#pragma once

#include "../UI/UIManager.h"

#include <memory>

class Command
{
    public:
        Command() = default;
        virtual bool Execute() = 0;
    protected:
        std::shared_ptr<UIManager> interface;
};