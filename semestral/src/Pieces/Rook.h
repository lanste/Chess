/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Piece.h"

class Rook : public Piece
{
    public:
        Rook(const bool & col);
        int makeMove(const ::coordinates & startPos, const ::coordinates & endPos) override;
        void Print(std::ostream & os) override;
        void Save(std::ofstream os) override;
        std::shared_ptr<Piece> CreateInstance() override;
    protected:
};