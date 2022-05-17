/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Piece.h" // base class

class King : public Piece
{
    public:
        King(const bool & col) : Piece('K', col){};
        void Save(std::ofstream os) override;
        std::shared_ptr<Piece> CreateInstance() override;
    protected:
};
