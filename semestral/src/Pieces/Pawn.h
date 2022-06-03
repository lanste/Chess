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
        void Save(std::ofstream os) override;
        int makeMove(const coordinates & startPos, const coordinates & endPos,
                const std::array<std::array<std::shared_ptr<Piece>, 8>, 8> & board) override;
    protected:
        bool moved;
        bool doubleStep;
};
