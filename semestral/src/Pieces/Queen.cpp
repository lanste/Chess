//
// Created by teodor on 07.05.22.
//

#include "Queen.h"

Queen::Queen(const bool & col) : Piece('Q', col)
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
    for (const auto & elem: moves)
    {
        bool hitFlag = false;
        coordinates pos = startPos;
        while((pos.x <= 7 && pos.x >= 0) && (pos.y <= 7 && pos.y >= 0) )
        {
            if(board[pos.x][pos.y] != nullptr && startPos != pos)
                hitFlag = true;
            if(pos == endPos)
            {
                if(hitFlag)
                    return 1;
                return 0;
            }
            pos = pos + elem;
            //cout << x << " " << y << endl;
        }
    }
    return 1;
}
