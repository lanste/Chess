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
        int x = startPos.x;
        int y = startPos.y;
        while((x <= 7 && x >= 0) && (y <= 7 && y >= 0) )
        {
            if(x == endPos.x && y == endPos.y)
                return 0;
            x += elem.x;
            y += elem.y;
            //cout << x << " " << y << endl;
        }
    }
    return 1;
}
