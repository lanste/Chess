/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Board.h" // base class

//#include "../UI/Interface.h"
//#include "../UI/ITerminal.h"
#include "../Utility/moveTypes.h"
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
         * Populates game board with Pieces in initial setup
         * @param empty - if set to true, creates board without any pieces
         */
        explicit ClassicalChessBoard(const bool & empty);

        /**
         * Initializes board from file
         * @param data - tokenized altered FEN string and additional data \n
         * 0 - board layout \n
         * 1 - castling ability \n
         * 2 - enpassant ability
         * 3 -
         * 4 -
         */
        void Initialize(const std::vector<std::string> & data) override;
        /**
         * see Board.h
         * @return
         */
        std::string State() override;

        /**
         * Generates string representing the board in slightly altered FEN notation
         * @return
         */
        std::string Save() override;
        bool isMove(std::string & command) override;
        ChessMove ProcessMove(const bool & colour, const std::string & m) override;

        int ExecuteMove(const ChessMove & move) override;

        std::string announceWinner(const bool & colour) override;
        //void revertMove();
    protected:

        [[nodiscard]] bool isContested(const coordinates & tile, const char & exclude = 'O');

        [[nodiscard]] bool findMate(const bool & colour);

        [[nodiscard]] bool kingCanMove(const bool & colour);

        /**
         * Tries to find any relevant piece on the board that could prevent check
         * @param colour
         * @return true if any piece was found
         */
        [[nodiscard]] bool canPrevent(const bool & colour);

        /**
         * Stores 2 instances of the board.
         * Dummy for staging, data as the actual state
         * if dummy state is validated, the move is executed on "data" board
         */
        struct ChessBoard{
            bool real;
            std::array<std::array<std::shared_ptr<Piece>, 8>,8> data;
            std::array<std::array<std::shared_ptr<Piece>, 8>,8> dummy;
            /**
             * switches between dummy and data
             * @param input
             */
            void isReal(const bool & input);
            std::shared_ptr<Piece> & operator [] (const coordinates & i);
        };
        coordinates bKingPos, wKingPos;
        coordinates dummybKingPos, dummywKingPos;
        ChessBoard board;
        std::vector<std::shared_ptr<Piece>> onBoard;
        std::vector<std::shared_ptr<Piece>> affected;
        int check;
        bool checkmate;
};