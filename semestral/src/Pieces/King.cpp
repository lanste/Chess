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
int King::makeMove(const int & startPos, const int & endPos)
{
    return 0;
}
