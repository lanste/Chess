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

void Rook::Save(std::ofstream os)
{

}
int Rook::makeMove(const coordinates & startPos, const coordinates & endPos)
{
    return 0;
}
void Rook::Print(std::ostream & os)
{
    Piece::Print(os);
}
