/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "../UI/Interface.h"
#include "../UI/ITerminal.h"
#include "../Application/coordinates.h"

#include <memory>
#include <vector>
#include <fstream>
/**
 * Abstract class
 * Represents any figure on the gameboard
 */
class Piece
{
    public:
        Piece();
//----------------------------------------------------------------------------------------------------------------------
        Piece(const char32_t & s, const bool & c) : symbol(s), colour(c)/*, coords(0,0)*/ {}
//----------------------------------------------------------------------------------------------------------------------
        /**
         * Evaluates if move requested by player is valid for this piece
         * @param startPos
         * @param endPos
         * @param board
         * @return 1 if pseudo valid move, 0 otherwise, ?? 2-n special move ??
         */
        virtual int makeMove(const coordinates & startPos, const coordinates & endPos,
                             const std::array<std::array<std::shared_ptr<Piece>, 8>,8> & board) = 0;
//----------------------------------------------------------------------------------------------------------------------
        /**
         * @return pointer to object of derived class (Chess pieces)
         */
        virtual std::shared_ptr<Piece> CreateInstance() = 0;
//----------------------------------------------------------------------------------------------------------------------
        /**
         * Displays Piece on the board
         * @param os
         */
        virtual void Print(std::ostream & os);
//----------------------------------------------------------------------------------------------------------------------
        /**
         * glorified print method
         * prints Piece in a format used by SaveManager
         * @param os file to write to
         */
        virtual char Save();
//----------------------------------------------------------------------------------------------------------------------
        bool getColour();
//----------------------------------------------------------------------------------------------------------------------
    protected:
        std::vector<coordinates> moves;
        char symbol;
        bool colour; // 0 = white | 1 = black
        //coordinates coords;
};
