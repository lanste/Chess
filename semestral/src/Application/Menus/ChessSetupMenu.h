//
// Created by teodor on 14.05.22.
//

#pragma once

#include "Menu.h"

class ChessSetupMenu : public Menu
{
    public:
        ChessSetupMenu() = default;
        int Show() override;
        int ExecCommand(const std::string & command) override;
};