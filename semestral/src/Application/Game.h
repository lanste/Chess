/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "../UI/Interface.h"
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
        Game(const std::shared_ptr<Interface> & ui);
        Game(const std::shared_ptr<Interface> & ui, const std::shared_ptr<Board> & game); // unnecessary ?
        int Initialize(const std::shared_ptr<Interface> & ui, const std::shared_ptr<Board> & board, const std::vector<std::shared_ptr<Player>> & p);
        int Start();
    protected:
        std::shared_ptr<Interface> interface;
        std::shared_ptr<Board> game;
        std::vector<std::shared_ptr<Player>> players;
};


