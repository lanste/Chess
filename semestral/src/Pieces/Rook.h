/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Piece.h"

class Rook : public Piece
{
    public:
        Rook(const bool & col);
        int makeMove(const coordinates & startPos, const coordinates & endPos,
                const std::array<std::array<std::shared_ptr<Piece>, 8>, 8> & board) override;
        void Save(std::ofstream os) override;
        std::shared_ptr<Piece> CreateInstance() override;
    protected:
};