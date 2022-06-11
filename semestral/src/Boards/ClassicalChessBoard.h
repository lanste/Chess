/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Board.h" // base class

//#include "../UI/Interface.h"
//#include "../UI/ITerminal.h"
#include "../Application/moveTypes.h"
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
        ClassicalChessBoard(const bool & empty);
        void Initialize(const std::vector<std::string> & data) override;
        std::string State() override;

        /**
         * Generates string representing the board in slightly altered FEN notation
         * @return
         */
        std::string Save() override;
        ChessMove ProcessMove(const bool & colour, const std::string & m) override;
        bool isMove(std::string & command) override;
        int ExecuteMove(const ChessMove & move) override;
        //void revertMove();
    protected:
        int findCheck(/*const bool & colour*/);
        bool findMate(const bool & colour);

        struct ChessBoard{
            bool real;
            std::array<std::array<std::shared_ptr<Piece>, 8>,8> data;
            std::array<std::array<std::shared_ptr<Piece>, 8>,8> dummy;
            void isReal(const bool & dfg);
            std::shared_ptr<Piece> & operator [] (const coordinates & i);
        };
        ChessBoard board;
        std::vector<std::shared_ptr<Piece>> onBoard;
        coordinates bKingPos, wKingPos;
        int check;
        bool checkmate;
};