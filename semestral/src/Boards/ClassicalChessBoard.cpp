// Created by teodor on 08.05.22.
//
//


#include "ClassicalChessBoard.h"

ClassicalChessBoard::ClassicalChessBoard(const bool & empty) : Board("Chess")
{
    //Initialize();
    if (empty)
    {
        check = 2;
        checkmate = false;
        return;
    }
#define white false
#define black true
#define queenSide true
#define kingSide false

    onBoard.push_back(board[0][0] = std::make_shared<Rook>(white, kingSide, coordinates{0, 0}));
    onBoard.push_back(board[0][1] = std::make_shared<Knight>(white, coordinates{0, 1}));
    onBoard.push_back(board[0][2] = std::make_shared<Bishop>(white, coordinates{0, 2}));
    onBoard.push_back(board[0][3] = std::make_shared<Queen>(white, coordinates{0, 3}));
    onBoard.push_back(board[0][4] = std::make_shared<King>(white, coordinates{0, 4}));
    onBoard.push_back(board[0][5] = std::make_shared<Bishop>(white, coordinates{0, 5}));
    onBoard.push_back(board[0][6] = std::make_shared<Knight>(white, coordinates{0, 6}));
    onBoard.push_back(board[0][7] = std::make_shared<Rook>(white, queenSide, coordinates{0, 7}));
    for (int i = 0; i < 8; ++i)
    {
        onBoard.push_back(board[1][i] = std::make_shared<Pawn>(white, coordinates{1, i}));
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
        onBoard.push_back(board[6][i] = std::make_shared<Pawn>(black, coordinates{6, i}));
    }
    onBoard.push_back(board[7][0] = std::make_shared<Rook>(black, kingSide, coordinates{7, 0}));
    onBoard.push_back(board[7][1] = std::make_shared<Knight>(black, coordinates{7, 1}));
    onBoard.push_back(board[7][2] = std::make_shared<Bishop>(black, coordinates{7, 2}));
    onBoard.push_back(board[7][3] = std::make_shared<Queen>(black, coordinates{7, 3}));
    onBoard.push_back(board[7][4] = std::make_shared<King>(black, coordinates{7, 4}));
    onBoard.push_back(board[7][5] = std::make_shared<Bishop>(black, coordinates{7, 5}));
    onBoard.push_back(board[7][6] = std::make_shared<Knight>(black, coordinates{7, 6}));
    onBoard.push_back(board[7][7] = std::make_shared<Rook>(black, queenSide, coordinates{7, 7}));

    bKingPos = {7, 4};
    wKingPos = {0, 4}; // todo unnecessary?
    check = 2;
    checkmate = false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ClassicalChessBoard::Initialize(const std::vector<std::string> & data)
{
    enum pieces
    {
        whitePawn = 'P', whiteRook = 'R', whiteKnight = 'N', whiteBishop = 'B', whiteQueen = 'Q', whiteKing = 'K',
        blackPawn = 'p', blackRook = 'r', blackKnight = 'n', blackBishop = 'b', blackQueen = 'q', blackKing = 'k'
    };

    bool bShort = false,
            bLong = false,
            wShort = false,
            wLong = false,
            newEmpty = false;
    int row = 0, tile = 0;
    std::shared_ptr<Piece> pc;

    if (data.size() > 1)
    {
        for (const auto & cstlAb: data[1])
        {
            switch (cstlAb)
            {
                case 'K':
                    wShort = true;
                    break;
                case 'Q':
                    wLong = true;
                    break;
                case 'k':
                    bShort = true;
                    break;
                case 'q':
                    bLong = true;
                    break;
                default:
                    throw std::invalid_argument("Invalid savefile: unknown character in castling definition");
            }
        }
    }

    for (const auto & piece: data[0])
    {
        switch (piece) // there is something wrong about this
        {
            case whitePawn:
                pc = std::make_shared<Pawn>(false, coordinates{row, tile});
                break;
            case whiteRook:
                if (wShort && tile == 0 && row == 0)
                {
                    pc = std::make_shared<Rook>(false, false, coordinates{row, tile});
                    break;
                }
                if (wLong && tile == 7 && row == 0)
                {
                    pc = std::make_shared<Rook>(false, true, coordinates{row, tile});
                    break;
                }
                pc = std::make_shared<Rook>(false, coordinates{row, tile});
                break;
            case whiteKnight:
                pc = std::make_shared<Knight>(false, coordinates{row, tile});
                break;
            case whiteBishop:
                pc = std::make_shared<Bishop>(false, coordinates{row, tile});
                break;
            case whiteQueen:
                pc = std::make_shared<Queen>(false, coordinates{row, tile});
                break;
            case whiteKing:
                pc = std::make_shared<King>(false, coordinates{row, tile});
                wKingPos = {row, tile};
                break;
            case blackPawn:
                pc = std::make_shared<Pawn>(true, coordinates{row, tile});
                break;
            case blackRook:
                if (bShort && tile == 0 && row == 7)
                {
                    pc = std::make_shared<Rook>(true, false, coordinates{row, tile});
                    break;
                }
                if (bLong && tile == 7 && row == 7)
                {
                    pc = std::make_shared<Rook>(true, true, coordinates{row, tile});
                    break;
                }
                pc = std::make_shared<Rook>(true, coordinates{row, tile});
                break;
            case blackKnight:
                pc = std::make_shared<Knight>(true, coordinates{row, tile});
                break;
            case blackBishop:
                pc = std::make_shared<Bishop>(true, coordinates{row, tile});
                break;
            case blackQueen:
                pc = std::make_shared<Queen>(true, coordinates{row, tile});
                break;
            case blackKing:
                pc = std::make_shared<King>(true, coordinates{row, tile});
                bKingPos = {row, tile};
                break;
            case '/':
                ++row;
                tile = -1;
                break;
            case ' ':
                row = -1;
                break;
            default:
                int n = piece - '0' - 1;
                for (; n >= 0; --n)
                {
                    board[row][tile] = nullptr;
                    ++tile;
                }
                newEmpty = true;
                break;
        }
        if (row == -1)
            break;
        if (tile != -1 && !newEmpty)
        {
            board[row][tile] = pc;
            onBoard.push_back(pc);
            pc = nullptr;
        }
        if (!newEmpty)
            ++tile;
        newEmpty = false;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::string ClassicalChessBoard::State()
{
    /*
     * Could be simplified extremely
     * -> would loose some generality (todo) even though it doesn't have any at the moment
     */
    std::stringstream output;
    if (check == 0)
        output << "White check!\n";
    else if (check == 1)
        output << "White check!\n";
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
    enum specialMoves
    {
        VALID, INVALID, PROMOTION, ENPASSANT, SCASTLE, LCASTLE, CHECK, CHECKMATE
    };
    coordinates startPos(
            move[1] - '0' - 1,
            toupper(move[0]) - 'A'),
            endPos(
            move[3] - '0' - 1,
            toupper(move[2]) - 'A');

    std::shared_ptr<Piece> startPiece = board[startPos.x][startPos.y];
    std::shared_ptr<Piece> endPiece = board[endPos.x][endPos.y];
    if (startPos == endPos) // todo pieces should probably guard this
        return 1;
    if (startPiece == nullptr)
        return 1;
    if (startPiece->getColour() != colour)
        return 1;

    /* prevent King from selfcheck
    * this logic allows King to step into its own pieces
    * but that is caught later
    */
    if (toupper(startPiece->Save()) == 'K' || check == colour)
    {
        int tmpCheck = check;
        coordinates tmpKingPos = wKingPos;

        wKingPos = endPos;
        findCheck(colour);
        if (check == 0)
        {
            wKingPos = tmpKingPos;
            check = tmpCheck;
            return 1;
        }
        wKingPos = tmpKingPos;
        check = tmpCheck;
    }

    if (toupper(startPiece->Save()) == 'k' || check == colour)
    {
        int tmpCheck = check;
        coordinates tmpKingPos = bKingPos;

        bKingPos = endPos;
        findCheck(colour);
        if (check == 0)
        {
            bKingPos = tmpKingPos;
            check = tmpCheck;
            return 1;
        }
        bKingPos = tmpKingPos;
        check = tmpCheck;
    }
    switch (startPiece->makeMove(startPos, endPos, board))
    {
        case INVALID:
            return 1;
        case VALID:
        {
            auto holdPiece = board[startPos.x][startPos.y];
            board[startPos.x][startPos.y] = nullptr;
            holdPiece->updatePosition(endPos);
            if (holdPiece->Save() == 'K')
            {
                wKingPos = holdPiece->getPosition();
            }
            if (holdPiece->Save() == 'k')
            {
                bKingPos = holdPiece->getPosition();
            }
            board[endPos.x][endPos.y] = holdPiece;
            break;
        }
        case PROMOTION:
        {
            if (move.size() != 5)
                return 1;
            board[startPos.x][startPos.y] = nullptr;
            std::shared_ptr<Piece> promoted;
            switch (toupper(move[4]))
            {
                case 'N':
                    promoted = std::make_shared<Knight>(colour, endPos);
                    break;
                case 'B':
                    promoted = std::make_shared<Bishop>(colour, endPos);
                    break;
                case 'R':
                    promoted = std::make_shared<Rook>(colour, endPos);
                    break;
                case 'Q':
                    promoted = std::make_shared<Queen>(colour, endPos);
                    break;
                default:
                    return 1;
            }
            board[endPos.x][endPos.y] = promoted;
            board[endPos.x][endPos.y]->updatePosition(endPos);
            break;
        }
        case LCASTLE:
        {
            // king calling to castle already verified that it can castle
            // need to check relevant rook - LongCASTLE => over queen
            int row = startPos.x;
            Rook buddy = dynamic_cast<Rook &>(*(board[row][7]));
            if (buddy.canCastle())
            {
                if (board[startPos.x][startPos.y]->Save() == 'K')
                    wKingPos = endPos;
                if (board[startPos.x][startPos.y]->Save() == 'k')
                    bKingPos = endPos;
                auto holdKing = board[row][startPos.y];
                auto holdRook = board[row][7];
                board[row][startPos.y] = nullptr;
                board[row][7] = nullptr;
                board[row][endPos.y] = holdKing;
                // todo stupid workaround (make a move without moving)
                holdRook->makeMove({row, 7}, {row, 7}, board);
                board[row][endPos.y - 1] = holdRook;
                board[endPos.x][endPos.y]->updatePosition(endPos);
                board[endPos.x][endPos.y - 1]->updatePosition(endPos);
                break;
            }
            return 1;
        }
        case SCASTLE:
        {
            // king calling to castle already verified that it can castle
            // need to check relevant rook - LongCASTLE => over queen
            int row = startPos.x;
            Rook buddy = dynamic_cast<Rook &>(*(board[row][0]));
            if (buddy.canCastle())
            {
                if (board[startPos.x][startPos.y]->Save() == 'K')
                    wKingPos = endPos;
                if (board[startPos.x][startPos.y]->Save() == 'k')
                    bKingPos = endPos;
                auto holdKing = board[row][startPos.y];
                auto holdRook = board[row][0];
                board[row][startPos.y] = nullptr;
                board[row][0] = nullptr;
                // todo stupid workaround (make a move without moving)
                holdRook->makeMove({row, 0}, {row, 0}, board);
                board[row][endPos.y] = holdKing;
                board[row][endPos.y + 1] = holdRook;
                board[endPos.x][endPos.y]->updatePosition(endPos);
                board[endPos.x][endPos.y + 1]->updatePosition(endPos);
                break;
            }
            return 1;
        }
        case ENPASSANT:
        {
            auto holdPiece = board[startPos.x][startPos.y];
            board[startPos.x][startPos.y] = nullptr;
            board[endPos.x][endPos.y] = holdPiece;
            board[endPos.x][endPos.y]->updatePosition(endPos);
            board[endPos.x - 1][endPos.y] = nullptr;

            break;
        }
        default:
            break;
    }
    //if (endPiece != nullptr && endPiece->getColour() == colour)
    //{
    //    return 1;
    //}
    findCheck(colour);
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ClassicalChessBoard::findCheck(const bool & colour)
{
    for (const auto & piece: onBoard)
    {
        if (piece->makeMove(piece->getPosition(), wKingPos, board) == 0)
        {
            if (colour == white && piece->Save() == 'K')
                continue;
            check = white;
            return;
        }
        if (colour != black && piece->makeMove(piece->getPosition(), bKingPos, board) == 0)
        {
            check = black;
            return;
        }
    }
    check = 2;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

        if (moveSize == 5)
        {
            int lastLetter = toupper(move[4]);
            if (lastLetter != 'Q' && lastLetter != 'N' &&
                lastLetter != 'B' && lastLetter != 'R')
            {
                return false;
            }
        }
        if (moveSize > 5)
            return false;

        command = move;
        return true;
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::string ClassicalChessBoard::Save()
{
    std::stringstream output;
    int emptyCnt;
    bool bKing = false, wKing = false, wShort = false, wLong = false, bShort = false, bLong = false;
    for (const auto & row: board)
    {
        emptyCnt = 0;
        for (const auto & tile: row)
            if (tile != nullptr)
            {
                if (emptyCnt != 0)
                {
                    output << emptyCnt;
                    emptyCnt = 0;
                }
                output << tile->Save();
                if (tile->Save() == 'K')
                {
                    King * found = dynamic_cast<King *>(tile.get());
                    wKing = found->canCastle();
                }
                if (tile->Save() == 'k')
                {
                    King * found = dynamic_cast<King *>(tile.get());
                    bKing = found->canCastle();
                }

                if (tile->Save() == 'R')
                {
                    Rook * found = dynamic_cast<Rook *>(tile.get());
                    //Rook found = static_cast<Rook>(tile.get());
                    if (found->getSide())
                        wLong = found->canCastle();
                    else
                        wShort = found->canCastle();
                }
                if (tile->Save() == 'r')
                {
                    Rook * found = dynamic_cast<Rook *>(tile.get());
                    bool res = found->getSide();
                    if (res)
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
        if (emptyCnt != 0)
        {
            output << emptyCnt;
        }
        if (row != board.back())
            output << '/';
    }

    output << " ";

    if (wKing)
    {
        if (wShort)
            output << 'K';
        if (wLong)
            output << 'Q';
    }
    if (bKing)
    {
        if (bShort)
            output << 'k';
        if (bLong)
            output << 'q';
    }

    return output.str();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////