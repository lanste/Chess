//
// Created by teodor on 13.05.22.
//

#pragma once

#include "../Command.h"
#include "../../UI/UIManager.h"
#include "../../UI/ITerminal.h"

#include <memory>

class ComingSoonCmd : public Command
{
    public:
        ComingSoonCmd(const std::shared_ptr<UIManager> & ui);
        int Execute() override;
    protected:
        std::shared_ptr<UIManager> interface;
};