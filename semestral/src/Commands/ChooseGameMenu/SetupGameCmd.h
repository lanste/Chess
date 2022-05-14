//
// Created by teodor on 13.05.22.
//

#pragma once

#include "../Command.h"
#include "../../Boards/ClassicalChessBoard.h"
#include "../../Application/Game.h"
#include "../../Application/Menus/GameSetupMenu.h"

#include <memory>
#include <map>

class SetupGameCmd : public Command
{
    public:
        SetupGameCmd(const std::shared_ptr<Interface> & ui, const std::shared_ptr<Board> & board);
        int Execute() override;

    protected:
        std::shared_ptr<Interface> interface;
        Game game;
};


