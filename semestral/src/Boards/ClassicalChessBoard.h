/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Board.h" // base class

//#include "../UI/Interface.h"
//#include "../UI/ITerminal.h"
#include "../Pieces/Piece.h"
#include "../Pieces/King.h"
#include "../Pieces/Queen.h"
#include "../Pieces/Bishop.h"
#include "../Pieces/Knight.h"
#include "../Pieces/Rook.h"
#include "../Pieces/Pawn.h"

#include <array>

/**
 * Class representing rules and logic of classical chess
 */
class ClassicalChessBoard : public Board
{
    public:
        /**
         * Populates game board with Pieces, players pieces go to
         * the lower part of the board i.e. closer to player
         * @param playerColour decides which colour of Pieces to put to the lower part of the board (last part not true)
         */
        ClassicalChessBoard();
        void Initialize(const std::vector<std::string> & data);
        std::string State();

        /**
         * Generates string representing the board in slightly altered FEN notation
         * @return
         */
        std::string Save();
        int ProcessMove(const bool & colour, const std::string & m);
        bool isMove(std::string & command);
    protected:
        std::array<std::array<std::shared_ptr<Piece>, 8>,8> board;
};