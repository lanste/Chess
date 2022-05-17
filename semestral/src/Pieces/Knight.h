/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Piece.h"

class Knight : public Piece
{
    public:
        Knight(const bool & col) : Piece('N', col){};
        std::shared_ptr<Piece> CreateInstance() override;
        void Save(std::ofstream os) override;
};

void Knight::Save(std::ofstream os)
{

}
