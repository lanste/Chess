// Created by teodor on 08.05.22.
//
//


#include "ClassicalChessBoard.h"

ClassicalChessBoard::ClassicalChessBoard()
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ClassicalChessBoard::Initialize()
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::string ClassicalChessBoard::State()
{
    return {};
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ClassicalChessBoard::ProcessMove(...)
{
    return 0;
}
bool ClassicalChessBoard::isMove(std::stringstream & command)
{
    std::string head, move;
    command >> head;
    if(head == "move")
    {
        command >> move;
    }
    else
        move = head;
    if(move.size() != 4)
        return false;

    for(int i = 0; i <= 2; i += 2)
    {
        if(move[i] < 'A' || move[i] > 'H')
            return false;
        if(move[i+1] < '1' || move[i+1] > '8')
            return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////