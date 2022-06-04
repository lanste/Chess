//
// Created by teodor on 07.05.22.
//

#include "Rook.h"

Rook::Rook(const bool & col, const bool & nSide) : Piece('R', col),moved(false), side(nSide)
{
    moves = {{-1,0},
             {0,-1},
             {0,1},
             {1,0}};
}

Rook::Rook(const bool & col) : Piece('R', col), moved(true), side(false)
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

int Rook::makeMove(const coordinates & startPos, const coordinates & endPos,
        const std::array<std::array<std::shared_ptr<Piece>, 8>, 8> & board)
{
    for (const auto & elem: moves)
    {
        int x = startPos.x;
        int y = startPos.y;
        while((x <= 7 && x >= 0) && (y <= 7 && y >= 0) )
        {
            if(x == endPos.x && y == endPos.y)
            {
                moved = true;
                return 0;
            }
            x += elem.x;
            y += elem.y;
            //cout << x << " " << y << endl;
        }
    }
    return 1;
}
