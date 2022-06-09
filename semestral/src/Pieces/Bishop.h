/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Piece.h"

class Bishop : public Piece
{
    public:
        Bishop(const bool & col, const coordinates & myPos);
        std::shared_ptr<Piece> CreateInstance() override;
        int makeMove(const coordinates & startPos, const coordinates & endPos,
                const std::array<std::array<std::shared_ptr<Piece>, 8>, 8> & board) override;
    protected:
};
