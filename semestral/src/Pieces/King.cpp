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
             {0, 2},
             {0, -2}};
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
        //if((pos.x < 8 && pos.x > -1) && (pos.y < 8 && pos.y > -1))
        //    continue;
        if (pos == endPos)
        {
            int result = 1;
            if(board[endPos.x][endPos.y] != nullptr && board[endPos.x][endPos.y]->getColour() == colour)
                break;
            //request
            //long castle
            if(elem == moves[lcastle] && !moved && board[pos.x][5] == nullptr)
                result = 5;
            // short castle
            if(elem == moves[scastle] && !moved && board[pos.x][3] == nullptr)
                result = 4;
            if(elem != moves[lcastle] && elem != moves[scastle])
                result = 0;
            return result;
        }
    }
    return 1;
}
bool King::canCastle() const
{
    return !moved;
}
void King::updatePosition(const coordinates & newPos)
{
    pastPosition = position;
    position = newPos;
    ++moved;
}
void King::revertPosition()
{
    position = pastPosition;
    --moved;
}
