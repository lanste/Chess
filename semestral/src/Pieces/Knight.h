/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Piece.h"

class Knight : public Piece
{
    public:
        Knight(const bool & col, const coordinates & myPos);// : Piece('N', col){};
        std::shared_ptr<Piece> CreateInstance() override;
        int tryMove(const coordinates & startPos, const coordinates & endPos,
                const std::array<std::array<std::shared_ptr<Piece>, 8>, 8> & board) override;
};
