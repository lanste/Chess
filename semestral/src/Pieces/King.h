/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Piece.h" // base class

class King : public Piece
{
    public:
    King();
        std::shared_ptr<Piece> createInstance() override;
        void Print(UIManager & interface) override;
    protected:
        char symbol;
};
