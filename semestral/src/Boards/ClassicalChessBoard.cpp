// Created by teodor on 08.05.22.
//
//


#include "ClassicalChessBoard.h"

ClassicalChessBoard::ClassicalChessBoard()
{
    Initialize();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ClassicalChessBoard::Initialize()
{
#define white false
#define black true
    board[0][0] = std::make_shared<Rook>(white);
    board[0][1] = std::make_shared<Knight>(white);
    board[0][2] = std::make_shared<Bishop>(white);
    board[0][3] = std::make_shared<King>(white);
    board[0][4] = std::make_shared<Queen>(white);
    board[0][5] = std::make_shared<Bishop>(white);
    board[0][6] = std::make_shared<Knight>(white);
    board[0][7] = std::make_shared<Rook>(white);
    for (int i = 0; i < 8; ++i)
    {
        board[1][i] = std::make_shared<Pawn>(white);
    }
    for (int i = 2; i < 6; ++i)
    {
        for (int j = 0; i < 8; ++i)
        {
            board[i][j] = nullptr;
        }
    }
    for (int i = 0; i < 8; ++i)
    {
        board[6][i] = std::make_shared<Pawn>(black);
    }
    board[7][0] = std::make_shared<Rook>(black);
    board[7][1] = std::make_shared<Knight>(black);
    board[7][2] = std::make_shared<Bishop>(black);
    board[7][3] = std::make_shared<King>(black);
    board[7][4] = std::make_shared<Queen>(black);
    board[7][5] = std::make_shared<Bishop>(black);
    board[7][6] = std::make_shared<Knight>(black);
    board[7][7] = std::make_shared<Rook>(black);
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
    for (int i = 0; i < 8; ++i)
    {
        output << " " << static_cast<char>('A' + i);
        if (i == 7)
            output << ' ';
    }
    output << '\n';
    output << "  +" << std::string(17, '-') << '+';
    // actual board printing todo? methodize
    for (int i = 7; i >= 0; --i)
    {
        output << std::endl << i + 1 << " |";
        for (int j = 0; j < 8; ++j)
        {
            if (board[i][j])
            {
                output << ' ';
                board[i][j]->Print(output);
                if (j == 7)
                    output << ' ';
            }
            else
            {
                output << std::noskipws << " .";
                if (j == 7)
                    output << ' ';
            }
        }
        output << "| " << i + 1;
    }
    // end board print
    output << '\n';
    output << "  +" << std::string(17, '-') << '+' << std::endl << "   ";
    for (int i = 0; i < 8; ++i)
    {
        //cout << 'A' + i;
        output << ' ' << static_cast<char>('A' + i);
        if (i == 7)
            output << ' ';
    }
    output << ' ' << '\n';
    return output.str();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ClassicalChessBoard::ProcessMove(const std::string & move)
{
    coordinates startPos(
            move[1] - '0' - 1,
            toupper(move[0]) - 'A'),
            endPos(
            move[3] - '0' - 1,
            toupper(move[2]) - 'A');

    //std::cerr << '\n' << move[0] << std::endl;
    //std::cerr << 'A';

    if (board[startPos.x][startPos.y] == nullptr)
        return 1;
    if (board[startPos.x][startPos.y]->makeMove(startPos, endPos))
        return 1;

    if (board[endPos.x][endPos.y] != nullptr)
        return 1;

    auto holdPiece = board[startPos.x][startPos.y];
    board[startPos.x][startPos.y] = nullptr;
    board[endPos.x][endPos.y] = holdPiece;
    return 0;
}
bool ClassicalChessBoard::ifMoveParse(std::string & command)
{
    std::string head, move;
    if (command.size() < 4)
        return false;
    head = command.substr(0, 4);
    if (head == "move")
    {
        move = command.substr(5, 4);
    }
    else
        move = head;
    if (move.size() != 4)
        return false;


    if (toupper(move[0]) < 'A' || toupper(move[0]) > 'H')
        return false;
    if (move[1] < '1' || move[1] > '8')
        return false;
    if (toupper(move[2]) < 'A' || toupper(move[2]) > 'H')
        return false;
    if (move[3] < '1' || move[3] > '8')
        return false;

    command = move;
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////