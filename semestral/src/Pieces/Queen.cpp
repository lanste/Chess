//
// Created by teodor on 07.05.22.
//

#include "Queen.h"

Queen::Queen(const bool & col, const coordinates & myPos) : Piece('Q', col, myPos)
{
    moves = {{-1,0},
             {0,-1},
             {0,1},
             {1,0},
             {-1,-1},
             {1,-1},
             {-1,1},
             {1,1}};
}

std::shared_ptr<Piece> Queen::CreateInstance()
{
    return std::make_shared<Queen>(*this);
}
int Queen::makeMove(const coordinates & startPos, const coordinates & endPos,
        const std::array<std::array<std::shared_ptr<Piece>, 8>, 8> & board)
{
    if(position == endPos)
        return 1;
    for (const auto & elem: moves)
    {
        bool hitFlag = false;
        coordinates pos = position;
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
                // encountered any piece along the way
                if(hitFlag)
                {
                    // hit occured in target and it's piece of different colour
                    if(hitPos == endPos && board[pos.x][pos.y]->getColour() != colour)
                        return 0;
                    return 1;
                }
                //pastPosition = position;
                return 0;
            }
            pos = pos + elem;
            //cout << x << " " << y << endl;
        }
    }
    return 1;
}
