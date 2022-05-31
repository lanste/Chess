//
// Created by teodor on 07.05.22.
//

#include "King.h"

King::King(const bool & col) : Piece('K',col)
{
    moves = {{0,1},
             {1,0},
             {0,-1},
             {-1,0},
             {1,1},
             {1,-1},
             {-1,1},
             {-1,-1}};
}

std::shared_ptr<Piece> King::CreateInstance()
{
    return std::make_shared<King>(*this);
}

void King::Save(std::ofstream os)
{
    return;
}
int King::makeMove(const coordinates & startPos, const coordinates & endPos)
{
    for (const auto & elem: moves)
    {
        coordinates raw = startPos + elem;
        if (raw == endPos)
        {
            if (startPos.x == 7 && raw.x == 0)
                break;
            if (startPos.x == 0 && raw.x == 7)
                break;
            return 1;
        }
    }
    return 0;
}
void King::Print(std::ostream & os)
{
    Piece::Print(os);
}
