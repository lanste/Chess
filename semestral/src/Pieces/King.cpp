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

int King::tryMove(const coordinates & startPos, const coordinates & endPos,
        const std::array<std::array<std::shared_ptr<Piece>, 8>, 8> & board)
{
    if(startPos == endPos)
        return 1;
    for (const auto & elem: moves)
    {
        coordinates pos = startPos + elem;
        if((pos.x <= 7 && pos.x >= 0) && (pos.y <= 7 && pos.y >= 0))
            continue;
        if (pos == endPos)
        {
            int result = 0;
            if(board[endPos.x][endPos.y] != nullptr && board[endPos.x][endPos.y]->getColour() == colour)
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
            if (!moved)
                moved = true;
            //pastPosition = position;
            return result;
        }
    }
    return 1;
}
bool King::canCastle() const
{
    return !moved;
}
