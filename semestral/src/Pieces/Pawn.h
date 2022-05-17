/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Piece.h"

class Pawn : public Piece
{
    public:
        Pawn(const bool & col) : Piece('K', col){};
        std::shared_ptr<Piece> CreateInstance() override;
        void Save(std::ofstream os) override;
};
