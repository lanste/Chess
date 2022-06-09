//
// Created by teodor on 07.05.22.
//

#include "King.h"

King::King(const bool & col, const coordinates & myPos) : Piece('K', col, myPos), moved(false)
{
    moves = {{0, 1},
             {1, 0},
             {0, -1},
             {-1, 0},
             {1, 1},
             {1, -1},
             {-1, 1},
             {-1, -1},
             {0, -2},
             {0, 2},};
}

std::shared_ptr<Piece> King::CreateInstance()
{
    return std::make_shared<King>(*this);
}

int King::makeMove(const coordinates & startPos, const coordinates & endPos,
        const std::array<std::array<std::shared_ptr<Piece>, 8>, 8> & board)
{
    if(startPos == endPos)
        return 1;
    for (const auto & elem: moves)
    {
        coordinates pos = startPos + elem;
        if (pos == endPos)
        {
            int result = 1;
            if (startPos.x == 7 && pos.x == 0)
                break;
            if (startPos.x == 0 && pos.x == 7)
                break;
            //request
            //long castle
            if(elem == moves[lcastle] && !moved)
                result = 5;
            // short castle
            if(elem == moves[scastle] && !moved)
                result = 4;
            if(elem != moves[lcastle] && elem != moves[scastle])
                result = 0;
            if (!moved && result != 1)
                moved = true;
            //position = endPos;
            return result;
        }
    }
    return 1;
}
bool King::canCastle() const
{
    return !moved;
}
