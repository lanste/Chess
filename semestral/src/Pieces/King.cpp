//
// Created by teodor on 07.05.22.
//

#include "King.h"

King::King(const bool & col) : Piece('K',col), moved(false)
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

int King::makeMove(const coordinates & startPos, const coordinates & endPos,
        const std::array<std::array<std::shared_ptr<Piece>, 8>, 8> & board)
{
    for (const auto & elem: moves)
    {
        coordinates pos = startPos + elem;
        if (pos == endPos)
        {
            if (startPos.x == 7 && pos.x == 0)
                break;
            if (startPos.x == 0 && pos.x == 7)
                break;
            if(!moved)
                moved = true;
            return 0;
        }
    }
    return 1;
}
bool King::canCastle() const
{
    return !moved;
}
