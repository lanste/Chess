//
// Created by teodor on 07.05.22.
//

#include "Knight.h"

Knight::Knight(const bool & col) : Piece('N', col)
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

void Knight::Save(std::ofstream os)
{

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
                return 0;
            //cout << x << " " << y << endl;
        }
    }
    return 1;
}
