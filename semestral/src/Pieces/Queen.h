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
        int makeMove(const ::coordinates & startPos, const ::coordinates & endPos) override;
        std::shared_ptr<Piece> CreateInstance() override;
};
