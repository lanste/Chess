//
// Created by teodor on 07.05.22.
//

#include "King.h"

King::King(const bool & col) : Piece('K',col)
{
    moves.push_back(8);
    moves.push_back(-8);
    moves.push_back(1);
    moves.push_back(-1);
    moves.push_back(7);
    moves.push_back(9);
    moves.push_back(-7);
    moves.push_back(-9);
}

std::shared_ptr<Piece> King::CreateInstance()
{
    return std::make_shared<King>(*this);
}

void King::Save(std::ofstream os)
{
    return;
}
int King::makeMove(const coordinates & startPos, const coordinates & endPos)
{
    return 0;
}
void King::Print(std::ostream & os)
{
    Piece::Print(os);
}
