/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Piece.h"

class Bishop : public Piece
{
    public:
        Bishop(const bool & col) : Piece('B', col){};
        std::shared_ptr<Piece> CreateInstance() override;
        void Save(std::ofstream os) override;
};

void Bishop::Save(std::ofstream os)
{

}
