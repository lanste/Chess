//
// Created by teodor on 07.05.22.
//

#include "Knight.h"

Knight::Knight(const bool & col, const coordinates & myPos) : Piece('N', col, myPos)
{
    moves = {{1,2},
             {-1,2},
             {1,-2},
             {-1,-2},
             {2,1},
             {-2,1},
             {2,-1},
             {-2,-1}};
}

std::shared_ptr<Piece> Knight::CreateInstance()
{
    return std::make_shared<Knight>(*this);
}

int Knight::makeMove(const coordinates & startPos, const coordinates & endPos,
        const std::array<std::array<std::shared_ptr<Piece>, 8>, 8> & board)
{
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
                if(board[x][y] != nullptr && board[x][y]->getColour() != colour)
                    return 1;
                //position = endPos;
                return 0;
            }
            //cout << x << " " << y << endl;
        }
    }
    return 1;
}
