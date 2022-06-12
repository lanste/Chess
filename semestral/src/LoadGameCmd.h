//
// Created by teodor on 16.05.22.
//

#pragma once

#include "Command.h" // base class

#include "LaunchGameCmd.h"
#include "SaveManager.h"
#include "Player.h"
#include "LocalPlayer.h"
#include "OnlinePlayer.h"
#include "AI1.h"
#include "AI2.h"
#include "AI3.h"
#include "Board.h"
#include "ClassicalChessBoard.h"

class LoadGameCmd : public Command
{
    public:
        LoadGameCmd(const std::shared_ptr<Interface> & ui, const std::pair<time_t, std::string> & save);
        int Execute() override;
    protected:
        /**
         * Receives data from SaveManager, initializes Game class and passes board data to Board class to initialized
         * @param data
         * @return
         */
        int parseData(const std::vector<std::string> & data);
        std::shared_ptr<Interface> interface;
        int status, turn;
        std::shared_ptr<Board> board;
        std::vector<std::shared_ptr<Player>> players;
        std::string saveName;
};

