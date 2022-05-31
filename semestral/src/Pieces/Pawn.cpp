//
// Created by teodor on 07.05.22.
//

#include "Pawn.h"

Pawn::Pawn(const bool & col) : Piece('K', col)
{
    if(col)
    {
        moves = {{1,0}, {1,1},{1,-1}};
    }
    else
    {
        moves = {{-1,0}, {-1,1},{-1,-1}};
    }
}



std::shared_ptr<Piece> Pawn::CreateInstance()
{
    return std::make_shared<Pawn>(*this);
}
void Pawn::Save(std::ofstream os)
{

}

int Pawn::makeMove(const ::coordinates & startPos, const ::coordinates & endPos)
{
    //vector<coordinates> myMoves = {{1,0}, {1,1},{1,-1}};
    //vector<coordinates> myMoves = {{-1,0}, {-1,1},{-1,-1}};
    for (const auto & elem: moves)
    {
        int x = startPos.x;
        int y = startPos.y;
        if((x <= 7 && x >= 0) && (y <= 7 && y >= 0) )
        {
            x += elem.x;
            y += elem.y;
            if(x == endPos.x && y == endPos.y)
                return 1;
            //cout << x << " " << y << endl;
        }
    }
    return 0;
}
