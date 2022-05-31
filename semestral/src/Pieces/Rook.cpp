//
// Created by teodor on 07.05.22.
//

#include "Rook.h"

Rook::Rook(const bool & col) : Piece('R', col)
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

void Rook::Save(std::ofstream os)
{

}
int Rook::makeMove(const coordinates & startPos, const coordinates & endPos)
{
    for (const auto & elem: moves)
    {
        int x = startPos.x;
        int y = startPos.y;
        while((x <= 7 && x >= 0) && (y <= 7 && y >= 0) )
        {
            if(x == endPos.x && y == endPos.y)
                return 1;
            x += elem.x;
            y += elem.y;
            //cout << x << " " << y << endl;
        }
    }
    return 0;
}
void Rook::Print(std::ostream & os)
{
    Piece::Print(os);
}
