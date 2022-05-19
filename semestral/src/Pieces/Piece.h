/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "../UI/Interface.h"
#include "../UI/ITerminal.h"

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
        Piece(const char & s, const bool & c) : symbol(s), colour(c)/*, coords(0,0)*/ {}
//----------------------------------------------------------------------------------------------------------------------
        virtual int makeMove(const int & startPos, const int & endPos) const = 0;
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
        virtual void Save(std::ofstream os) = 0;
//----------------------------------------------------------------------------------------------------------------------
    protected:
        struct coordinates
        {
            coordinates(char h, int v) : horizontal(h), vertical(v){}
            char horizontal;
            int vertical;
        };
        std::vector<int> moves;
        char symbol;
        bool colour; // 0 = white | 1 = black
        //coordinates coords;
};
