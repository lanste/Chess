/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "../Boards/Board.h"
#include "../Boards/ClassicalChessBoard.h"

#include <memory>

/**
 * Player abstract class
 */
class Player
{
    public:
    Player() = default;
    //virtual bool makeTurn(std::shared_ptr<Board> & board) = 0;
    protected:
        bool colour;

};