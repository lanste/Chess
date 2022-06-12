/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "ITerminal.h"
#include "ClassicalChessBoard.h"
#include "LocalPlayer.h"
#include "AI1.h"
#include "AI2.h"
#include "AI3.h"
#include "BackCmd.h"
#include "SaveManager.h"
#include "Moves/ChessMove.h"
//#include "../Commands/Game/SaveGameCmd.h"


#include <memory>
#include <map>
#include <sstream>
#include <fstream>

/**
 *  Game manager class
 *  Holds all information about currently played game
 */
class Game
{
    public:
        Game() = default;
        Game(const std::shared_ptr<Interface> & ui);
        Game(const std::shared_ptr<Interface> & ui, const std::shared_ptr<Board> & board, const std::vector<std::shared_ptr<Player>> & p);
        Game(const std::shared_ptr<Interface> & ui, const std::shared_ptr<Board> & board, const int & status,
             const std::vector<std::shared_ptr<Player>> & p, const int & turn);
        int Initialize(const std::shared_ptr<Interface> & ui, const std::shared_ptr<Board> & board, const std::vector<std::shared_ptr<Player>> & p);
        int Start();
    private:
        std::string Show();
        int Save(const std::string & fileName);
        int status;
        bool initialized;
        size_t onTurn;
        std::map<std::string, std::shared_ptr<Command>> commands;
        std::shared_ptr<Interface> interface;
        std::shared_ptr<Board> game;
        std::vector<std::shared_ptr<Player>> players;
};


