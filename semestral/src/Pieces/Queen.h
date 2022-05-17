/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Piece.h"

class Queen : public Piece
{
    public:
        Queen(const bool & col) : Piece('Q', col){};
        std::shared_ptr<Piece> CreateInstance() override;
        void Save(std::ofstream os) override;
};

void Queen::Save(std::ofstream os)
{

}
