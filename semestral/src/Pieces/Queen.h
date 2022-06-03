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
        std::shared_ptr<Piece> CreateInstance() override;
        int makeMove(const coordinates & startPos, const coordinates & endPos,
                const std::array<std::array<std::shared_ptr<Piece>, 8>, 8> & board) override;
};
