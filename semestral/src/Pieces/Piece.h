/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "../UI/UIManager.h"
#include "../UI/ITerminal.h"

/**
 * Abstract class
 * Represents any figure on the gameboard
 */
class Piece
{
    public:
        Piece() = default;
        virtual void createInstance() = 0;
        virtual void Print(UIManager & interface) = 0;
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
