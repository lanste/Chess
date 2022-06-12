//
// Created by teodor on 07.05.22.
//

#include "Pawn.h"

Pawn::Pawn(const bool & col, const coordinates & myPos) : Piece('P', col, myPos), traveledSquares(0), moved(false), doubleStep(false)
{
    if (!col)
    {
        moves = {{1, 0},
                 {1, 1},
                 {1, -1},
                 {2, 0}};
    }
    else
    {
        moves = {{-1, 0},
                 {-1, 1},
                 {-1, -1},
                 {-2, 0}};
    }
}

std::shared_ptr<Piece> Pawn::CreateInstance()
{
    return std::make_shared<Pawn>(*this);
}
int Pawn::tryMove(const coordinates & startPos, const coordinates & endPos,
        const std::array<std::array<std::shared_ptr<Piece>, 8>, 8> & board)
{
    if (startPos == endPos)
        return 1;
    int validResult = 0;
    int forwardRank = colour?startPos.x-1:startPos.x+1;
    for (const auto & elem: moves)
    {
        coordinates pos = startPos;
        if ((pos.x <= 7 && pos.x >= 0) && (pos.y <= 7 && pos.y >= 0))
        {
            pos = pos + elem;
            if (pos == endPos)
            {
                doubleStep = false;
                //problematic
                if(!moved && moves.size() == 4 && elem == moves[3])
                   doubleStep = true;

                if (moves.size() == 4 && elem == moves[3] && // this move is doublestep
                        board[forwardRank][startPos.y] == nullptr && // no piece directly in front
                        board[endPos.x][endPos.y] == nullptr) // no pieces in endPos
                    validResult = 6;

                // attack moves
                if ((elem == moves[1] || elem == moves[2]))
                {
                    // no conventional target
                    if (board[endPos.x][endPos.y] == nullptr)
                    {
                        int targetRow = colour ? (endPos.x + 1) : (endPos.x - 1);
                        // en passant?
                        if (traveledSquares == 3 && board[targetRow][endPos.y] != nullptr)
                        {
                            auto * captured = dynamic_cast<Pawn *>((board[targetRow][endPos.y].get()));
                            if (captured && captured->getColour() != colour && captured->doubleStep)
                                validResult = 3;
                            else
                                return 1;
                        }
                        else
                        {
                            return 1;
                        }
                    }
                    else if(board[endPos.x][endPos.y]->getColour() == colour)
                    {
                        return 1;
                    }
                    else
                    {
                        validResult = 0;
                    }
                }
                // Standard move
                if (elem == moves[0] && board[endPos.x][endPos.y] != nullptr) //piece in the way
                    return 1;

                // Promotion
                if (endPos == coordinates(colour ? 0 : 7, endPos.y))
                    validResult = 2;
                if (!moved)
                {
                    moves.pop_back(); //last inserted is move by 2 - kinda stupid but ok
                    moved = true;
                }
                traveledSquares += abs(elem.x); //todo this is problem
                //pastPosition = position;
                return validResult;
            }
        }
    }
    return 1;
}
