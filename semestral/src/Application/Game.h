/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "../UI/UIManager.h"
#include "../UI/ITerminal.h"
#include "../Boards/Board.h"
#include "../Boards/ClassicalChessBoard.h"
#include "../Players/Player.h"
#include "../Players/LocalPlayer.h"
#include "../Players/AI1.h"
#include "../Players/AI2.h"
#include "../Players/AI3.h"

#include <memory>

/**
 *  Game manager class
 *  Holds all information about currently played game
 */
class Game
{
    public:
        Game(const std::shared_ptr<UIManager> & ui);
        Game(const std::shared_ptr<UIManager> & ui, const std::shared_ptr<Board> & game);
        int Start();
    protected:
        std::shared_ptr<UIManager> interface;
        std::shared_ptr<Board> gameState;
        std::vector<std::shared_ptr<Player>> players;
};


