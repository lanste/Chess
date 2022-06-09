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
                if(hitFlag && board[pos.x][pos.y]->getColour() == colour)
                    return 1;
                moved = true;
                //position = endPos;
                return 0;
            }
            pos = pos + elem;
            //cout << x << " " << y << endl;
        }
    }
    return 1;
}
