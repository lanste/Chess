//
// Created by teodor on 13.05.22.
//

#pragma once

#include "../Command.h"
#include "../../Boards/ClassicalChessBoard.h"
#include "../../Application/Game.h"
#include "../../Application/Menus/ChessSetupMenu.h"

#include <memory>

class PlayChessCmd : public Command
{
    public:
        PlayChessCmd(const std::shared_ptr<UIManager> & ui, const std::shared_ptr<Board> & board);
        int Execute() override;

    protected:
        Game game;
};


