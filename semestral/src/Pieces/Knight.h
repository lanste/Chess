/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Piece.h"

class Knight : public Piece
{
    public:
        Knight(const bool & col);// : Piece('N', col){};
        std::shared_ptr<Piece> CreateInstance() override;
        int makeMove(const int & startPos, const int & endPos) const override;
        void Save(std::ofstream os) override;
};
