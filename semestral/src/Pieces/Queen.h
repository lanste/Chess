/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Piece.h"

class Queen : public Piece
{
    public:
        Queen(const bool & col);
        void Save(std::ofstream os) override;
        void Print(std::ostream & os) override;
        int makeMove(const int & startPos, const int & endPos) override;
        std::shared_ptr<Piece> CreateInstance() override;
};
