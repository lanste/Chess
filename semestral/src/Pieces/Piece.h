/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "../UI/Interface.h"
#include "../UI/ITerminal.h"
#include "../Utility/coordinates.h"
//#include "../Application/moveTypes.h"

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
        Piece(const char & s, const bool & c, const coordinates myPos) : position(myPos), pastPosition(myPos), symbol(s), colour(c) {}
//----------------------------------------------------------------------------------------------------------------------
        /**
         * Evaluates if move requested by player is valid for this piece
         * @param startPos
         * @param endPos
         * @param board
         * @return 0 if pseudo valid move, 1 otherwise, ?? 2-n special move ??
         */
        virtual int tryMove(const coordinates & startPos, const coordinates & endPos,
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
        std::vector<coordinates> getMoves();
        coordinates getPosition();
        virtual void updatePosition(const coordinates & newPos);
        virtual void revertPosition();
//----------------------------------------------------------------------------------------------------------------------
    protected:
        std::vector<coordinates> moves;
        coordinates position;
        coordinates pastPosition;
        char symbol;
        bool colour; // 0 = white | 1 = black
        //coordinates coords;
};
