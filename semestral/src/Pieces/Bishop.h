/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Piece.h"

class Bishop : public Piece
{
    public:
        Bishop(const bool & col);
        std::shared_ptr<Piece> CreateInstance() override;
        void Save(std::ofstream os) override;
        int makeMove(const ::coordinates & startPos, const ::coordinates & endPos) override;
    protected:
};
