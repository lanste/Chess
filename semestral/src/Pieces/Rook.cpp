//
// Created by teodor on 07.05.22.
//

#include "Rook.h"

Rook::Rook(const bool & col, const bool & nSide, const coordinates & myPos) : Piece('R', col, myPos),moved(false), side(nSide)
{
    moves = {{-1,0},
             {0,-1},
             {0,1},
             {1,0}};
}

Rook::Rook(const bool & col, const coordinates & myPos) : Piece('R', col, myPos), moved(true), side(false)
{
    moves = {{-1,0},
             {0,-1},
             {0,1},
             {1,0}};
}

std::shared_ptr<Piece> Rook::CreateInstance()
{
    return std::make_shared<Rook>(*this);
}

int Rook::tryMove(const coordinates & startPos, const coordinates & endPos,
        const std::array<std::array<std::shared_ptr<Piece>, 8>, 8> & board)
{
    if(startPos == endPos)
        return 1;
    for (const auto & elem: moves)
    {
        bool hitFlag = false;
        coordinates pos = startPos;
        coordinates hitPos = {-1,-1};
        while((pos.x <= 7 && pos.x >= 0) && (pos.y <= 7 && pos.y >= 0) )
        {
            // currently examined square has a piece, it's not me and flag isn't set
            if(board[pos.x][pos.y] != nullptr && position != pos && !hitFlag)
            {
                hitPos = pos;
                hitFlag = true;
            }
            if(pos == endPos)
            {
                if(hitFlag)
                {
                    // hit occured in target and it's piece of different colour
                    if(hitPos == endPos && board[pos.x][pos.y]->getColour() != colour)
                        return 0;
                    return 1;
                }
                return 0;
            }
            pos = pos + elem;
        }
    }
    return 1;
}
void Rook::updatePosition(const coordinates & newPos)
{
    pastPosition = position;
    position = newPos;
    moved = true;
}
