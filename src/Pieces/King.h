/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Piece.h" // base class

class King : public Piece
{
    public:
        King(const bool & col, const coordinates & myPos);
        std::shared_ptr<Piece> CreateInstance() override;
        int tryMove(const coordinates & startPos, const coordinates & endPos,
                const std::array<std::array<std::shared_ptr<Piece>, 8>, 8> & board) override;
        bool canCastle() const;
        void updatePosition(const coordinates & newPos) override;
        void revertPosition() override;
    protected:
        enum emove{scastle = 8, lcastle = 9}; // readability helper enum
        int moved;
};
