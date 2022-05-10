/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Board.h" // base class

#include "../UI/UIManager.h"
#include "../UI/ITerminal.h"
#include "../Pieces/Piece.h"
#include "../Pieces/King.h"
#include "../Pieces/Queen.h"
#include "../Pieces/Bishop.h"
#include "../Pieces/Knight.h"
#include "../Pieces/Rook.h"
#include "../Pieces/Pawn.h"

#include <array>

/**
 * Class representing 8x8 chess board
 */
class ClassicalChessBoard : public Board
{
    public:
        /**
         * Populates game board with Pieces, players pieces go to
         * the lower part of the board i.e. closer to player
         * @param playerColour decides which colour of Pieces to put to the lower part of the board
         */
        ClassicalChessBoard(const bool & playerColour);
    protected:
        std::array<std::array<std::shared_ptr<Piece>, 8>, 8> board;
};