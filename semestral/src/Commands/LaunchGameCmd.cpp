//
// Created by teodor on 14.05.22.
//

#include "LaunchGameCmd.h"

LaunchGameCmd::LaunchGameCmd(const std::shared_ptr<Interface> & ui, const std::shared_ptr<Board> & board , const std::vector<std::shared_ptr<Player>> & players) : interface(ui), game(Game(ui, board, players))
{}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LaunchGameCmd::LaunchGameCmd(const std::shared_ptr<Interface> & ui, const std::shared_ptr<Board> & board,
        const int & status, const std::vector<std::shared_ptr<Player>> & players, const int & turn) : game(ui,board,status,players, turn)
{

}
int LaunchGameCmd::Execute()
{
        return game.Start();
}

