//
// Created by teodor on 07.05.22.
//

#include "Pawn.h"

Pawn::Pawn(const bool & col) : Piece('P', col), moved(false)
{
    if(!col)
    {
        moves = {{1,0}, {1,1},{1,-1},{2,0}};
    }
    else
    {
        moves = {{-1,0}, {-1,1},{-1,-1},{-2,0}};
    }
}



std::shared_ptr<Piece> Pawn::CreateInstance()
{
    return std::make_shared<Pawn>(*this);
}
void Pawn::Save(std::ofstream os)
{

}
int Pawn::makeMove(const coordinates & startPos, const coordinates & endPos,
        const std::array<std::array<std::shared_ptr<Piece>, 8>, 8> & board)
{
    doubleStep = false;
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
            {
                if(moves.size() == 4 && elem == moves[3])
                {
                    doubleStep = true;
                }
                if(endPos == coordinates(colour?0:7,endPos.y))
                    return 2;
                if(!moved)
                {
                    moves.pop_back(); //last inserted is move by 2 - kinda stupid but ok
                    moved = true;
                }
                return 0;
            }
            //cout << x << " " << y << endl;
        }
    }
    return 1;
}
