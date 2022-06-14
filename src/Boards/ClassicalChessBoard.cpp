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
    board.isReal(true);
    onBoard.push_back(board[{0, 0}] = std::make_shared<Rook>(white, kingSide, coordinates{0, 0}));
    onBoard.push_back(board[{0, 1}] = std::make_shared<Knight>(white, coordinates{0, 1}));
    onBoard.push_back(board[{0, 2}] = std::make_shared<Bishop>(white, coordinates{0, 2}));
    onBoard.push_back(board[{0, 3}] = std::make_shared<Queen>(white, coordinates{0, 3}));
    onBoard.push_back(board[{0, 4}] = std::make_shared<King>(white, coordinates{0, 4}));
    onBoard.push_back(board[{0, 5}] = std::make_shared<Bishop>(white, coordinates{0, 5}));
    onBoard.push_back(board[{0, 6}] = std::make_shared<Knight>(white, coordinates{0, 6}));
    onBoard.push_back(board[{0, 7}] = std::make_shared<Rook>(white, queenSide, coordinates{0, 7}));
    for (int i = 0; i < 8; ++i)
    {
        onBoard.push_back(board[{1, i}] = std::make_shared<Pawn>(white, coordinates{1, i}));
    }
    for (int i = 2; i < 6; ++i)
    {
        for (int j = 0; i < 8; ++i)
        {
            board[{i, j}] = nullptr;
        }
    }
    for (int i = 0; i < 8; ++i)
    {
        onBoard.push_back(board[{6, i}] = std::make_shared<Pawn>(black, coordinates{6, i}));
    }
    onBoard.push_back(board[{7, 0}] = std::make_shared<Rook>(black, kingSide, coordinates{7, 0}));
    onBoard.push_back(board[{7, 1}] = std::make_shared<Knight>(black, coordinates{7, 1}));
    onBoard.push_back(board[{7, 2}] = std::make_shared<Bishop>(black, coordinates{7, 2}));
    onBoard.push_back(board[{7, 3}] = std::make_shared<Queen>(black, coordinates{7, 3}));
    onBoard.push_back(board[{7, 4}] = std::make_shared<King>(black, coordinates{7, 4}));
    onBoard.push_back(board[{7, 5}] = std::make_shared<Bishop>(black, coordinates{7, 5}));
    onBoard.push_back(board[{7, 6}] = std::make_shared<Knight>(black, coordinates{7, 6}));
    onBoard.push_back(board[{7, 7}] = std::make_shared<Rook>(black, queenSide, coordinates{7, 7}));

    board.dummy = board.data;
    bKingPos = {7, 4};
    dummybKingPos = {7, 4};
    wKingPos = {0, 4};
    dummywKingPos = {0, 4};
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

    board.isReal(true);
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
                pc = std::make_shared<Pawn>(white, coordinates{row, tile});
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
                dummywKingPos = {row, tile};
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
                dummybKingPos = {row, tile};
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
                    board[{row, tile}] = nullptr;
                    ++tile;
                }
                newEmpty = true;
                break;
        }
        if (row == -1)
            break;
        if (tile != -1 && !newEmpty)
        {
            //pc->updatePosition({row, tile});
            //pc->updatePosition({row, tile});
            board[{row, tile}] = pc;
            onBoard.push_back(pc);
            pc = nullptr;
        }
        if (!newEmpty)
            ++tile;
        newEmpty = false;
    }
    board.dummy = board.data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::string ClassicalChessBoard::State()
{
    /*
     * Could be simplified extremely
     * -> would loose some generality (todo) even though it doesn't have any at the moment
     */
    std::stringstream output;
    if (checkmate)
    {
        // todo
    }
    if (check == 0)
        output << "White check!\n";
    else if (check == 1)
        output << "Black check!\n";
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
            if (board[{i, j}])
            {
                output << ' ';
                board[{i, j}]->Print(output);
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

ChessMove ClassicalChessBoard::ProcessMove(const bool & colour, const std::string & move)
{
    ChessMove output;// initialize dummy move
    // switches which board is being altered - staging or executing
    board.isReal(not output.isDummy());

    //std::cout << "Processmove start: " << board.real << std::endl;

    //auto beforeMove = board;
    //std::vector<std::pair<std::shared_ptr<Piece>,coordinates>> removed;
    coordinates startPos(
            move[1] - '0' - 1,
            toupper(move[0]) - 'A'),
            endPos(
            move[3] - '0' - 1,
            toupper(move[2]) - 'A');

    std::shared_ptr<Piece> startPiece = board[startPos];
    std::shared_ptr<Piece> endPiece = board[endPos];

    if (startPiece == nullptr)
        return output.inValidate();
    if (startPiece->getColour() != colour)
        return output.inValidate();

    switch (startPiece->tryMove(startPos, endPos, board.data))
    {
        case INVALID:
            return output.inValidate();
        case VALID:
        {
            // if this move leads to removing enemys piece
            if (board[endPos] != nullptr && board[endPos]->getColour() != colour)
                affected.push_back(board[endPos]);
            affected.push_back(board[startPos]);
            output.setValidMove(startPos, endPos, VALID);
            break;
        }
        case PROMOTION:
        {
            if (move.size() != 5)
                return output.inValidate();
            if (board[endPos] != nullptr && board[endPos]->getColour() != colour)
                affected.push_back(board[endPos]);
            affected.push_back(board[startPos]);
            output.setPromotion(startPos, endPos, PROMOTION, move[4]);
            break;
        }
        case LCASTLE:
        {
            // king calling to castle already verified that it can castle
            // need to check relevant rook - LongCASTLE - queens side
            int row = startPos.x;
            Rook buddy = dynamic_cast<Rook &>(*(board[{row, 0}]));
            if (buddy.canCastle())
            {
                // king cannot cross over contested tiles
                // the other one will be examined alongside check
                if (isContested({row, 3}, colour))
                    return output.inValidate();
                output.setCastle(startPos, LCASTLE, buddy.getPosition());
                break;
            }
            return output.inValidate();
        }
        case SCASTLE:
        {
            // king calling to castle already verified that it can castle
            // need to check relevant rook - ShortCASTLE - kings side
            int row = startPos.x;
            Rook buddy = dynamic_cast<Rook &>(*(board[{row, 7}]));
            if (buddy.canCastle())
            {
                // king cannot cross over contested tiles
                // the other one will be examined alongside check
                if (isContested({row, 5}, colour))
                    return output.inValidate();
                output.setCastle(startPos, SCASTLE, buddy.getPosition());
                break;
            }
            return output.inValidate();
        }
        case ENPASSANT:
        {
            //should be validated by pawn
            int targetRank = colour ? endPos.x + 1 : endPos.x - 1;
            if (board[endPos] != nullptr && board[endPos]->getColour() != colour)
                affected.push_back(board[{targetRank, endPos.y}]);
            affected.push_back(board[startPos]);
            output.setEnPassant(startPos, endPos, ENPASSANT);
            break;
        }
        case DOUBLESTEP:
            if (board[endPos] != nullptr && board[endPos]->getColour() != colour)
                affected.push_back(board[endPos]);
            affected.push_back(board[startPos]);
            output.setValidMove(startPos, endPos, DOUBLESTEP);
            break;
        default:
            break;
    }

    ExecuteMove(output); // executes move on dummy board

    if (isContested(dummywKingPos, white))
        check = white;
    else if (isContested(dummybKingPos, black))
        check = black;
    else
        check = 2;
    if (check == colour)
    {
        return output.inValidate();
    }
    if (check != 2)
        checkmate = findMate(colour);
    if (checkmate)
    {
        output.checkMate();
        return output.validate();
    }
    output.setColour(colour);
    return output.validate();
}

int ClassicalChessBoard::ExecuteMove(const ChessMove & move)
{
    //std::cout << "Execute start: " << board.real << std::endl;
    if (not move.isValid() && not move.isDummy())
    {
        //std::cout << "Execute Invalid move" << std::endl;
        board.dummy = board.data;
        return 1;
    }

    board.isReal(not move.isDummy());

    if (move.isCheckMate())
        return 2;

    //std::cout << "Execute after checks: " << board.real << std::endl;
    //std::cerr << "white king: " << wKingPos.x << wKingPos.y << std::endl;
    //std::cerr << "black king: " << bKingPos.x << bKingPos.y << std::endl;

    coordinates startPos = move.startPos();
    coordinates endPos = move.endPos();

    switch (move.moveType())
    {
        case INVALID:
            //board.dummy = board.data;
            return 1;
        case VALID:
        {
            auto holdPiece = board[startPos];
            board[startPos] = nullptr;
            holdPiece->updatePosition(endPos);
            if (holdPiece->Save() == 'K')
            {
                if (move.isDummy())
                    dummywKingPos = holdPiece->getPosition();
                else
                    wKingPos = dummywKingPos;
            }
            if (holdPiece->Save() == 'k')
            {
                if (move.isDummy())
                    dummybKingPos = holdPiece->getPosition();
                else
                    bKingPos = dummybKingPos;
            }
            board[endPos] = holdPiece;
            break;
        }
        case PROMOTION:
        {
            board[startPos] = nullptr;
            if (board[endPos] != nullptr)
            {
                board[endPos] = nullptr;
            }
            std::shared_ptr<Piece> promoted;
            switch (move.promotionResult())
            {
                case 'n':
                    promoted = std::make_shared<Knight>(move.getColour(), endPos);
                    break;
                case 'b':
                    promoted = std::make_shared<Bishop>(move.getColour(), endPos);
                    break;
                case 'r':
                    promoted = std::make_shared<Rook>(move.getColour(), endPos);
                    break;
                case 'q':
                    promoted = std::make_shared<Queen>(move.getColour(), endPos);
                    break;
                default:
                    return 1;
            }
            board[endPos] = promoted;
            board[endPos]->updatePosition(endPos);
            break;
        }
        case LCASTLE:
        {
            int row = startPos.x;
            Rook buddy = dynamic_cast<Rook &>(*(board[endPos]));
            if (board[startPos]->Save() == 'K')
            {
                if (move.isDummy())
                    dummywKingPos = board[startPos]->getPosition();
                else
                    wKingPos = dummywKingPos;
            }
            if (board[startPos]->Save() == 'k')
            {
                if (move.isDummy())
                    dummybKingPos = board[startPos]->getPosition();
                else
                    bKingPos = dummybKingPos;
            }

            auto holdKing = board[{row, 4}];
            auto holdRook = board[endPos];
            board[{row, 4}] = nullptr;
            board[{row, 0}] = nullptr;
            board[{row, 2}] = holdKing;
            board[{row, 3}] = holdRook;
            board[{row, 2}]->updatePosition({row, 2});
            board[{row, 3}]->updatePosition({row, 3});
            break;
        }
        case SCASTLE:
        {
            int row = startPos.x;
            Rook buddy = dynamic_cast<Rook &>(*(board[endPos]));
            if (board[startPos]->Save() == 'K')
            {
                if (move.isDummy())
                    dummywKingPos = board[startPos]->getPosition();
                else
                    wKingPos = dummywKingPos;
            }
            if (board[startPos]->Save() == 'k')
            {
                if (move.isDummy())
                    dummybKingPos = board[startPos]->getPosition();
                else
                    bKingPos = dummybKingPos;
            }
            auto holdKing = board[{row, startPos.y}];
            auto holdRook = board[endPos];
            board[{row, startPos.y}] = nullptr;
            board[{row, 7}] = nullptr;
            board[{row, 6}] = holdKing;
            board[{row, 5}] = holdRook;
            board[{row, 6}]->updatePosition({row, 6});
            board[{row, 5}]->updatePosition({row, 5});
            break;
        }
        case ENPASSANT:
        {
            auto holdPiece = board[startPos];
            int targetRank = holdPiece->getColour() ? endPos.x + 1 : endPos.x - 1;
            board[startPos] = nullptr;
            board[endPos] = holdPiece;
            board[endPos]->updatePosition(endPos);
            board[{targetRank, endPos.y}] = nullptr;
            break;
        }
        case DOUBLESTEP:
        {
            auto holdPiece = board[startPos];
            board[startPos] = nullptr;

            holdPiece->updatePosition(endPos);
            board[endPos] = holdPiece;
            break;
        }
        default:
            break;
    }
    return 0;
}
bool ClassicalChessBoard::isContested(const coordinates & tile, const char & exclude)
{
    for (const auto & piece: onBoard)
    {
        auto pCopy = piece->CreateInstance();
        if (exclude != 'O' && (exclude == pCopy->getColour() || pCopy->Save() == exclude))
            continue;
        // can any piece reach king from its position (except the king itself)
        if (pCopy->tryMove(pCopy->getPosition(), tile, board.dummy) == 0)
        {
            return true;
        }
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool ClassicalChessBoard::findMate(const bool & colour)
{
    if (kingCanMove(colour))
    {
        return false;
    }
    if (canPrevent(colour))
    {
        return false;
    }
    return true;
}

bool ClassicalChessBoard::kingCanMove(const bool & colour)
{
    coordinates checkedKingPos;
    if (check == white)
        checkedKingPos = wKingPos;
    else
        checkedKingPos = bKingPos;
    auto king = board[checkedKingPos];
    for (const auto & move: king->getMoves())
    {
        coordinates dest = checkedKingPos + move;

        if (king->tryMove(checkedKingPos, dest, board.dummy) != 1 && !isContested(dest, king->getColour()))
        {
            return true;
        }
    }
    return false;
}

bool ClassicalChessBoard::canPrevent(const bool & colour)
{
    coordinates checkedKingPos;
    if (check == white)
        checkedKingPos = wKingPos;
    else
        checkedKingPos = bKingPos;

    for (const auto & piece: onBoard)
    {
        if (piece->getColour() != board[checkedKingPos]->getColour())
            continue;
        auto pc = piece->CreateInstance();
        for (const auto & move: pc->getMoves())
        {
            coordinates dest = pc->getPosition() + move;
            if (pc->tryMove(pc->getPosition(), dest, board.dummy))
                if (not isContested(checkedKingPos, board[checkedKingPos]->getColour()))
                {
                    return true;
                }
        }
    }
    return false;
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
    for (const auto & row: board.data)
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
        if (row != board.data.back())
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
std::string ClassicalChessBoard::announceWinner(const bool & colour)
{
    return std::string(!colour ? "White wins!\n" : "Black wins!\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
std::shared_ptr<Piece> & ClassicalChessBoard::ChessBoard::operator [](const coordinates & i)
{
    if (real)
        return data[i.x][i.y];
    else
        return dummy[i.x][i.y];
}
void ClassicalChessBoard::ChessBoard::isReal(const bool & input)
{
    real = input;
}
