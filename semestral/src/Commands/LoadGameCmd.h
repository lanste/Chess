//
// Created by teodor on 16.05.22.
//

#pragma once

#include "Command.h" // base class

#include "LaunchGameCmd.h"
#include "../SaveManager.h"
#include "../Players/Player.h"
#include "../Players/LocalPlayer.h"
#include "../Players/OnlinePlayer.h"
#include "../Players/AI1.h"
#include "../Players/AI2.h"
#include "../Players/AI3.h"
#include "../Boards/Board.h"
#include "../Boards/ClassicalChessBoard.h"

class LoadGameCmd : public Command
{
    public:
        LoadGameCmd(const std::shared_ptr<Interface> & ui, const std::pair<time_t, std::string> & save);
        int Execute() override;
    protected:
        int parseData(const std::vector<std::string> & data);
        std::shared_ptr<Interface> interface;
        int status, turn;
        std::shared_ptr<Board> board;
        std::vector<std::shared_ptr<Player>> players;
        std::string saveName;
};

