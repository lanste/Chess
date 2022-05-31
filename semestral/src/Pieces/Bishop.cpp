//
// Created by teodor on 07.05.22.
//

#include "Bishop.h"

Bishop::Bishop(const bool & col) : Piece('B', col)
{
    moves.push_back(9);
    moves.push_back(7);
    moves.push_back(-7);
    moves.push_back(-9);
}

std::shared_ptr<Piece> Bishop::CreateInstance()
{
    return std::make_shared<Bishop>(*this);
}
void Bishop::Save(std::ofstream os)
{

}
int Bishop::makeMove(const coordinates & startPos, const coordinates & endPos)
{
    return 0;
}
