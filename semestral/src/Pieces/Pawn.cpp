//
// Created by teodor on 07.05.22.
//

#include "Pawn.h"

Pawn::Pawn(const bool & col) : Piece('K', col)
{
    moves.push_back(8);
    moves.push_back(7); //attacks?
    moves.push_back(9);
    moves.push_back(16);
}



std::shared_ptr<Piece> Pawn::CreateInstance()
{
    return std::make_shared<Pawn>(*this);
}
void Pawn::Save(std::ofstream os)
{

}
int Pawn::makeMove(const int & startPos, const int & endPos)
{
    for(const auto & elem : moves)
    {
        int raw = startPos + elem;
        if(raw == endPos)
        {
            if(startPos % 8 == 7 && raw % 8 == 0)
                break;
            if(startPos % 8 == 0 && raw % 8 == 7)
                break;
            if(startPos > 56)
                break;
            if(moves.size() == 4)
                moves.pop_back();
            return 0;
        }
    }
    return 1;
}
