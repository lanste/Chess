//
// Created by teodor on 07.05.22.
//

#include "Knight.h"

Knight::Knight(const bool & col) : Piece('N', col)
{
    moves.push_back(17);
    moves.push_back(15);
    moves.push_back(10);
    moves.push_back(-6);
    moves.push_back(-10);
    moves.push_back(6);
    moves.push_back(-15);
    moves.push_back(-17);
}

std::shared_ptr<Piece> Knight::CreateInstance()
{
    return std::make_shared<Knight>(*this);
}

void Knight::Save(std::ofstream os)
{

}
int Knight::makeMove(const coordinates & startPos, const coordinates & endPos)
{
    return 0;
}
void Knight::Print(std::ostream & os)
{
    Piece::Print(os);
}
int Knight::makeMove(const ::coordinates & startPos, const ::coordinates & endPos)
{
    return 0;
}
