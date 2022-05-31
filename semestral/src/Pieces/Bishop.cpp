//
// Created by teodor on 07.05.22.
//

#include "Bishop.h"

Bishop::Bishop(const bool & col) : Piece('B', col)
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
void Bishop::Save(std::ofstream os)
{

}
int Bishop::makeMove(const coordinates & startPos, const coordinates & endPos)
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
