//
// Created by teodor on 07.05.22.
//

#include "Bishop.h"

Bishop::Bishop(const bool & col, const coordinates & myPos) : Piece('B', col, myPos)
{
    moves = {{-1, -1},
             {1,  -1},
             {-1, 1},
             {1,  1}};
}

std::shared_ptr<Piece> Bishop::CreateInstance()
{
    return std::make_shared<Bishop>(*this);
}
int Bishop::makeMove(const coordinates & startPos, const coordinates & endPos,
        const std::array<std::array<std::shared_ptr<Piece>, 8>, 8> & board)
{
    for (const auto & elem: moves)
    {
        bool hitFlag = false;
        coordinates pos = startPos;
        //int x = startPos.x;
        //int y = startPos.y;
        while((pos.x <= 7 && pos.x >= 0) && (pos.y <= 7 && pos.y >= 0) )
        {
            if(board[pos.x][pos.y] != nullptr && startPos != pos)
                hitFlag = true;
            if(pos == endPos)
            {
                if(hitFlag && board[pos.x][pos.y]->getColour() == colour)
                    return 1;
                //position = endPos;
                return 0;
            }
            pos = pos + elem;
            //cout << x << " " << y << endl;
        }
    }
    return 1;
}
