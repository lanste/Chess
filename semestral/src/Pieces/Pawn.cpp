//
// Created by teodor on 07.05.22.
//

#include "Pawn.h"

Pawn::Pawn(const bool & col) : Piece('K', col)
{
    moves.push_back(8);
    //moves.push_back(7); //attacks?
    //moves.push_back(9);
}



std::shared_ptr<Piece> Pawn::CreateInstance()
{
    return std::make_shared<Pawn>(*this);
}
void Pawn::Save(std::ofstream os)
{

}
int Pawn::makeMove(const int & startPos, const int & endPos) const
{

    return 0;
}
