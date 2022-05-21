/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Piece.h" // base class

class King : public Piece
{
    public:
        King(const bool & col);// : Piece('K', col){};
        void Save(std::ofstream os) override;
        int makeMove(const int & startPos, const int & endPos) override;
        std::shared_ptr<Piece> CreateInstance() override;
    protected:
};
