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
