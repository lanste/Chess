/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Piece.h"

class Rook : public Piece
{
    public:
        Rook(const bool & col, const bool & side);
        Rook(const bool & col);
        int makeMove(const coordinates & startPos, const coordinates & endPos,
                const std::array<std::array<std::shared_ptr<Piece>, 8>, 8> & board) override;
        std::shared_ptr<Piece> CreateInstance() override;
        bool canCastle() const {return !moved;}
        bool getSide() const {return side;}
    protected:
        bool moved;
        bool side;
};