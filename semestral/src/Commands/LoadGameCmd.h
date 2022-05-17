//
// Created by teodor on 16.05.22.
//

#pragma once

#include "Command.h"
#include "../Application/SaveManager.h"

class LoadGameCmd : public Command
{
    public:
        LoadGameCmd(const std::shared_ptr<Interface> & ui, const std::pair<time_t, std::string> & save);
        int Execute() override;
    protected:
        std::shared_ptr<Interface> interface;
};

