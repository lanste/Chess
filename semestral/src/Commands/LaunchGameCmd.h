//
// Created by teodor on 14.05.22.
//

#pragma once

#include "Command.h"
#include "../Application/Game.h"

class LaunchGameCmd : public Command
{
    public:
        LaunchGameCmd(const std::shared_ptr<Interface> & ui, const std::shared_ptr<Board> & board , const std::vector<std::shared_ptr<Player>> & players);
        LaunchGameCmd(const std::shared_ptr<Interface> & ui, const std::shared_ptr<Board> & board, const int & status ,
                      const std::vector<std::shared_ptr<Player>> & players, const int & turn);
        int Execute() override;
    protected:
        std::shared_ptr<Interface> interface;
        Game game;
};


