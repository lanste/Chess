//
// Created by teodor on 13.05.22.
//

#include "PlayChessCmd.h"

PlayChessCmd::PlayChessCmd(const std::shared_ptr<UIManager> & ui, const std::shared_ptr<Board> & board) : game(Game(ui, board))
{

}

int PlayChessCmd::Execute()
{
    ChessSetupMenu menu;
    while(true)
    {

    }
    game.Start();
    return 0;
}
