/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "../UI/Interface.h"
#include "../UI/ITerminal.h"

#include <memory>
/**
 * Abstract class \n
 * Represents any figure on the gameboard
 */
class Piece
{
    public:
        Piece() = default;
        /**
         * @return pointer to object of derived class (Chess pieces)
         */
        virtual std::shared_ptr<Piece> createInstance() = 0;
        virtual void Print(Interface & interface) = 0;
    protected:
        struct coordinates
        {
            coordinates(char h, int v) : horizontal(h), vertical(v){}
            char horizontal;
            int vertical;
        };
        char symbol;
        bool colour; // 0 = white | 1 = black
};
