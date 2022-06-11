/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Piece.h"

class Rook : public Piece
{
    public:
        Rook(const bool & col, const bool & side, const coordinates & myPos);
        Rook(const bool & col, const coordinates & myPos);
        int tryMove(const coordinates & startPos, const coordinates & endPos,
                const std::array<std::array<std::shared_ptr<Piece>, 8>, 8> & board) override;
        std::shared_ptr<Piece> CreateInstance() override;
        bool canCastle() const {return !moved;}
        bool getSide() const {return side;}
    protected:
        bool moved;
    public:
        void updatePosition(const coordinates & newPos) override;
    protected:
        bool side;
};