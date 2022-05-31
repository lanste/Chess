//
// Created by teodor on 07.05.22.
//

#include "Queen.h"

Queen::Queen(const bool & col) : Piece('Q', col)
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

std::shared_ptr<Piece> Queen::CreateInstance()
{
    return std::make_shared<Queen>(*this);
}
void Queen::Print(std::ostream & os)
{
    Piece::Print(os);
}
void Queen::Save(std::ofstream os)
{

}