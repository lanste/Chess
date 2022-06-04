// Created by teodor on 08.05.22.
//
//


#include "ClassicalChessBoard.h"

ClassicalChessBoard::ClassicalChessBoard()
{
    //Initialize();
#define white false
#define black true
#define queenSide true
#define kingSide false

    board[0][0] = std::make_shared<Rook>(white, kingSide);
    board[0][1] = std::make_shared<Knight>(white);
    board[0][2] = std::make_shared<Bishop>(white);
    board[0][3] = std::make_shared<King>(white);
    board[0][4] = std::make_shared<Queen>(white);
    board[0][5] = std::make_shared<Bishop>(white);
    board[0][6] = std::make_shared<Knight>(white);
    board[0][7] = std::make_shared<Rook>(white, queenSide);
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
    board[7][0] = std::make_shared<Rook>(black, kingSide);
    board[7][1] = std::make_shared<Knight>(black);
    board[7][2] = std::make_shared<Bishop>(black);
    board[7][3] = std::make_shared<King>(black);
    board[7][4] = std::make_shared<Queen>(black);
    board[7][5] = std::make_shared<Bishop>(black);
    board[7][6] = std::make_shared<Knight>(black);
    board[7][7] = std::make_shared<Rook>(black, queenSide);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ClassicalChessBoard::Initialize()
{

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

int ClassicalChessBoard::ProcessMove(const bool & colour, const std::string & move)
{
    enum specialMoves{VALID, INVALID, PROMOTION, SCASTLE, LCASTLE, ENPASSANT, CHECK};
    coordinates startPos(
            move[1] - '0' - 1,
            toupper(move[0]) - 'A'),
            endPos(
            move[3] - '0' - 1,
            toupper(move[2]) - 'A');

    std::shared_ptr<Piece> startPiece = board[startPos.x][startPos.y];
    std::shared_ptr<Piece> endPiece = board[endPos.x][endPos.y];
    if (startPiece == nullptr)
        return 1;
    if(startPiece->getColour() != colour)
        return 1;

    switch(startPiece->makeMove(startPos, endPos, board))
    {
        case INVALID:
            return 1;
        case VALID:{
            auto holdPiece = board[startPos.x][startPos.y];
            board[startPos.x][startPos.y] = nullptr;
            board[endPos.x][endPos.y] = holdPiece;
            break;}
        case PROMOTION:{
            board[startPos.x][startPos.y] = nullptr;
            std::shared_ptr<Piece> promoted;
            switch(toupper(move[4]))
            {
                case 'N':
                    promoted = std::make_shared<Knight>(colour);
                    break;
                case 'B':
                    promoted = std::make_shared<Bishop>(colour);
                    break;
                case 'R':
                    promoted = std::make_shared<Rook>(colour);
                    break;
                case 'Q':
                    promoted = std::make_shared<Queen>(colour);
                    break;
                default:
                    return 1;
            }
            board[endPos.x][endPos.y] = promoted;
            break;}
        case LCASTLE:
            break;
        case SCASTLE:
            break;
        case ENPASSANT:{
            auto holdPiece = board[startPos.x][startPos.y];
            board[startPos.x][startPos.y] = nullptr;
            board[endPos.x][endPos.y] = holdPiece;
            board[endPos.x - 1][endPos.y] = nullptr;
            break;}
        default:
            break;
    }

    if(endPiece != nullptr && endPiece->getColour() == colour)
    {
        return 1;
    }

    return 0;
}
bool ClassicalChessBoard::isMove(std::string & command)
{
    std::string head, move;
    if (command.size() < 4)
        return false;
    head = command.substr(0, 4);
    if (head == "move")
    {
        move = command.substr(5);
    }
    else
        move = command;

    size_t moveSize = move.size();
    if (moveSize >= 4)
    {
        if (toupper(move[0]) < 'A' || toupper(move[0]) > 'H')
            return false;
        if (move[1] < '1' || move[1] > '8')
            return false;
        if (toupper(move[2]) < 'A' || toupper(move[2]) > 'H')
            return false;
        if (move[3] < '1' || move[3] > '8')
            return false;

        if(moveSize == 5)
        {
            int lastLetter = toupper(move[4]);
            if (lastLetter != 'Q' && lastLetter != 'N' &&
                lastLetter != 'B' && lastLetter != 'R')
            {
                return false;
            }
        }
        if(moveSize > 5)
            return false;

        command = move;
        return true;
    }
    return false;
}
std::string ClassicalChessBoard::Save()
{
    std::stringstream output;
    int emptyCnt;
    bool bKing = false, wKing = false, wShort = false, wLong = false, bShort = false, bLong = false;
    for(const auto & row : board)
    {
        emptyCnt = 0;
        for(const auto & tile : row)
        if(tile != nullptr)
        {
            if(emptyCnt != 0)
            {
                output << emptyCnt;
                emptyCnt = 0;
            }
            output << tile->Save();
            if(tile->Save() == 'K')
            {
                King found = static_cast<King>(tile.get());
                wKing = found.canCastle();
            }
            if(tile->Save() == 'k')
            {
                King found = static_cast<King>(tile.get());
                bKing = found.canCastle();
            }

            if(tile->Save() == 'R')
            {
                Rook * found = dynamic_cast<Rook*>(tile.get());
                //Rook found = static_cast<Rook>(tile.get());
                if(found->getSide())
                    wLong = found->canCastle();
                else
                    wShort = found->canCastle();
            }
            if(tile->Save() == 'r')
            {
                Rook * found = dynamic_cast<Rook*>(tile.get());
                bool res = found->getSide();
                if(res)
                {

                    bLong = found->canCastle();
                }
                else
                {
                    bShort = found->canCastle();
                }
            }

        }
        else
            ++emptyCnt;
        if(emptyCnt != 0)
        {
            output << emptyCnt;
            emptyCnt = 0;
        }
        if(row != board.back())
            output << '/';
    }

    output << " ";

    if(wKing)
    {
        if(wShort)
            output << 'K';
        if(wLong)
            output << 'Q';
    }
    if(bKing)
    {
        if(bShort)
            output << 'k';
        if(bLong)
            output << 'q';
    }

    return output.str();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////