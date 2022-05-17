/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Piece.h"

class Rook : public Piece
{
    public:
        Rook(const bool & col) : Piece('R', col){};
        std::shared_ptr<Piece> CreateInstance() override;
        void Save(std::ofstream os) override;
};

void Rook::Save(std::ofstream os)
{

}
