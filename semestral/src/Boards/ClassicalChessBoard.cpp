// Created by teodor on 08.05.22.
//
//


#include "ClassicalChessBoard.h"

ClassicalChessBoard::ClassicalChessBoard()
{
#define white false
#define black true
    board[0] = std::make_shared<Rook>(white);
    board[1] = std::make_shared<Knight>(white);
    board[2] = std::make_shared<Bishop>(white);
    board[3] = std::make_shared<King>(white);
    board[4] = std::make_shared<Queen>(white);
    board[5] = std::make_shared<Bishop>(white);
    board[6] = std::make_shared<Knight>(white);
    board[7] = std::make_shared<Rook>(white);
    for(int i = 8; i < 16; ++i)
    {
        board[i] = std::make_shared<Pawn>(white);
    }
    for(int i = 16; i < 48; ++i)
    {
        board[i] = nullptr;
    }
    for(int i = 48; i < 56; ++i)
    {
        board[i] = std::make_shared<Pawn>(black);
    }
    board[56] = std::make_shared<Rook>(black);
    board[57] = std::make_shared<Knight>(black);
    board[58] = std::make_shared<Bishop>(black);
    board[59] = std::make_shared<King>(black);
    board[60] = std::make_shared<Queen>(black);
    board[61] = std::make_shared<Bishop>(black);
    board[62] = std::make_shared<Knight>(black);
    board[63] = std::make_shared<Rook>(black);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ClassicalChessBoard::Initialize()
{
#define white false
#define black true
    board[0] = std::make_shared<Rook>(white);
    board[1] = std::make_shared<Knight>(white);
    board[2] = std::make_shared<Bishop>(white);
    board[3] = std::make_shared<King>(white);
    board[4] = std::make_shared<Queen>(white);
    board[5] = std::make_shared<Bishop>(white);
    board[6] = std::make_shared<Knight>(white);
    board[7] = std::make_shared<Rook>(white);
    for(int i = 8; i < 16; ++i)
    {
        board[i] = std::make_shared<Pawn>(white);
    }
    for(int i = 16; i < 48; ++i)
    {
        board[i] = nullptr;
    }
    for(int i = 48; i < 56; ++i)
    {
        board[i] = std::make_shared<Pawn>(black);
    }
    board[56] = std::make_shared<Rook>(black);
    board[57] = std::make_shared<Knight>(black);
    board[58] = std::make_shared<Bishop>(black);
    board[59] = std::make_shared<King>(black);
    board[60] = std::make_shared<Queen>(black);
    board[61] = std::make_shared<Bishop>(black);
    board[62] = std::make_shared<Knight>(black);
    board[63] = std::make_shared<Rook>(black);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
std::string ClassicalChessBoard::State()
{
    /*
     * Could be simplified extremely
     * -> would loose some generality (todo) even though it doesn't have any at the moment
     */
    std::stringstream output;
    output << "   ";
    for(int i = 0; i < 8; ++i)
    {
        output << " " << static_cast<char>('A' + i);
        if(i == 7)
            output << ' ';
    }
    output << '\n';
    output << "  +" << std::string(17, '-') << '+';
    for(int i = 0; i < 64; ++i)
    {
        if(i % 8 == 0)
            output << std::endl << (i/8) + 1 << " |";
        if(board[i])
        {
            output << ' ';
            board[i]->Print(output);
            if(i % 8 == 7)
                output << ' ';
        }
        else
        {
            output << std::noskipws << " .";
            if(i % 8 == 7)
                output << ' ';
        }
        if(i % 8 == 7)
            output << "| " << (i+1) / 8;
    }
    output << '\n';
    output << "  +" << std::string(17, '-') << '+' << std::endl << "   ";
    for(int i = 0; i < 8; ++i)
    {
        //cout << 'A' + i;
        output << ' ' << static_cast<char>('A' + i);
        if(i == 7)
            output << ' ';
    }
    output << ' ' <<'\n';
    return output.str();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ClassicalChessBoard::ProcessMove(const std::string & move)
{
    int startPos, endPos;

    //std::cerr << '\n' << move[0] << std::endl;
    //std::cerr << 'A';

    startPos = (toupper(move[0]) - 'A') + (move[1] - '0' - 1) * 8;



    endPos   = (toupper(move[2]) - 'A') + (move[3] - '0' - 1) * 8;




    if(board[startPos] == nullptr)
        return 1;
    if(board[startPos]->makeMove(startPos,endPos))
        return 1;

    if(board[endPos] != nullptr)
        return 1;

    auto holdPiece = board[startPos];
    board[startPos] = nullptr;
    board[endPos] = holdPiece;
    return 0;
}
bool ClassicalChessBoard::ifMoveParse(std::string & command)
{
    std::string head, move;
    if(command.size() < 4)
        return false;
    head = command.substr(0,4);
    if(head == "move")
    {
        move = command.substr(5,4);
    }
    else
        move = head;
    if(move.size() != 4)
        return false;


    if(toupper(move[0]) < 'A' || toupper(move[0]) > 'H')
            return false;
    if(move[1] < '1' || move[1] > '8')
            return false;
    if(toupper(move[2]) < 'A' || toupper(move[2]) > 'H')
        return false;
    if(move[3] < '1' || move[3] > '8')
        return false;

    command = move;
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////