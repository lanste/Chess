//
// Created by teodor on 07.05.22.
//

#include "Rook.h"

Rook::Rook(const bool & col) : Piece('R', col)
{
    moves.push_back(1);
    moves.push_back(-1);
    moves.push_back(8);
    moves.push_back(-8);
}
std::shared_ptr<Piece> Rook::CreateInstance()
{
    return std::make_shared<Rook>(*this);
}

int Rook::makeMove(const int & startPos, const int & endPos) const
{
    return 0;
}
void Rook::Save(std::ofstream os)
{

}
