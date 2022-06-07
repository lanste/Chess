//
// Created by teodor on 07.05.22.
//

#include "Pawn.h"

Pawn::Pawn(const bool & col) : Piece('P', col), traveledSquares(0), moved(false)
{
    if(!col)
    {
        moves = {{1,0}, {1,1},{1,-1},{2,0}};
    }
    else
    {
        moves = {{-1,0}, {-1,1},{-1,-1},{-2,0}};
    }
}



std::shared_ptr<Piece> Pawn::CreateInstance()
{
    return std::make_shared<Pawn>(*this);
}
int Pawn::makeMove(const coordinates & startPos, const coordinates & endPos,
        const std::array<std::array<std::shared_ptr<Piece>, 8>, 8> & board)
{
    int validResult = 0;
    doubleStep = false;
    for (const auto & elem: moves)
    {
        coordinates pos = startPos;
        if((pos.x <= 7 && pos.x >= 0) && (pos.y <= 7 && pos.y >= 0) )
        {
            pos = pos + elem;
            if(pos == endPos)
            {
                if(moves.size() == 4 && elem == moves[3]) // this move is doublestep
                    doubleStep = true;

                // En Passant
                if((elem == moves[1] || elem == moves[2]) && // attack move was used
                   traveledSquares == 3 &&  // en passant rule
                   board[endPos.x - 1][endPos.y] != nullptr && // enpassant target is a piece
                   board[endPos.x][endPos.y] == nullptr// conventional attack is invalid
                        ) // todo this is unreadable and i feel like YandereDev
                {
                    Pawn captured = dynamic_cast<Pawn&>(*(board[endPos.x - 1][endPos.y]));
                    if(captured.doubleStep)
                        validResult = 3;
                    else
                        return 1;
                }// Conventional attack
                else if((elem == moves[1] || elem == moves[2]) && // attack move was used
                    (board[endPos.x][endPos.y] == nullptr || // but there is no piece
                    /*(board[endPos.x][endPos.y] != nullptr &&*/ board[endPos.x][endPos.y]->getColour() == colour))//) // or there is a piece of the same colour
                    return 1;

                // Standard move
                if(elem == moves[0] && board[endPos.x][endPos.y] != nullptr) //piece in the way
                    return 1;

                // Promotion
                if(endPos == coordinates(colour?0:7,endPos.y))
                    validResult = 2;
                if(!moved)
                {
                    moves.pop_back(); //last inserted is move by 2 - kinda stupid but ok
                    moved = true;
                }
                traveledSquares += abs(elem.x);
                return validResult;
            }
        }
    }
    return 1;
}
