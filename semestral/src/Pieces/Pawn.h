/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Piece.h"

class Pawn : public Piece
{
    public:
        Pawn(const bool & col);
        std::shared_ptr<Piece> CreateInstance() override;
        int makeMove(const coordinates& startPos, const coordinates & endPos) override;
        void Save(std::ofstream os) override;
    protected:
        bool moved;
};
