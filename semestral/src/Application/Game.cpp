//
// Created by teodor on 08.05.22.
//

#include "Game.h"
#include "SaveManager.h"


Game::Game(const std::shared_ptr<Interface> & ui) : interface(ui)
{
    initialized = false;
    status = 0;
}
Game::Game(const std::shared_ptr<Interface> & ui, const std::shared_ptr<Board> & board, const int & nStatus,
        const std::vector<std::shared_ptr<Player>> & p, const int & turn) : status(nStatus), onTurn(turn), interface(ui), game(board), players(p)
{
    //commands.emplace("save", std::make_shared<SaveGameCmd>(this));
    commands.emplace("exit", std::make_shared<BackCmd>());
    //commands.emplace("help", std::make_shared<GameHelpCmd>(interface));
    commands.emplace("save", nullptr);
    //commands.emplace("exit", std::make_shared<>());


    initialized = true;
}
Game::Game(const std::shared_ptr<Interface> & ui, const std::shared_ptr<Board> & board, const std::vector<std::shared_ptr<Player>> & p) : interface(ui), game(board), players(p)
{
    //commands.emplace("save", std::make_shared<SaveGameCmd>(this));
    commands.emplace("exit", std::make_shared<BackCmd>());
    //commands.emplace("help", std::make_shared<GameHelpCmd>(interface));
    commands.emplace("save", nullptr);
    //commands.emplace("exit", std::make_shared<>());

    onTurn = 0;
    initialized = true;
    status = 0;
}
int Game::Initialize(const std::shared_ptr<Interface> & ui, const std::shared_ptr<Board> & board,
        const std::vector<std::shared_ptr<Player>> & p)
{
    onTurn = 0;
    initialized = true;
    status = 0;
    return 0;
}

int Game::Start()
{
#define main_loop while(true) // lol

    if(not initialized)
        throw std::runtime_error("FATAL: call to game start without prior initialization");
    //interface->Display(game->State());

    std::string command;
    std::string argument;
    size_t playerCnt = players.size();
    main_loop
    {
        for(; onTurn < playerCnt; ++onTurn)
        {
            //std::cerr << "game.start.mainLoop" << std::endl;
            interface->Display(players[onTurn]->getColour()?"black":"white"); // placeholder just for chess
            interface->Display("'s turn\n");
            interface->Display(Show());
            command = players[onTurn]->makeTurn(interface);
           // interface->Receive(command);
            /*
             * commands here can have arguments, delimited by space
             * -> load whole line to stream and decompose word by word
            */
            std::stringstream cmdStream(command);
            //std::cerr << cmdStream.str();
            cmdStream >> command;
            const auto cmd = commands.find(command);

            if (cmd != commands.end())
            {
                if (command == "save") // this is stupid todo fix
                {
                    cmdStream >> argument;
                    if(Save(argument))
                    {
                        interface->Display("Game \"" + argument + "\" successfully saved");
                    }
                    else
                    {
                        interface->Display("Saving unsuccessful");
                    }
                    --onTurn;
                    continue;
                    //status = saveManager.Save(argument, *this);
                }
                else
                {
                    status = cmd->second->Execute();
                }
                if(status)
                    return 1;
            }

            std::string move = cmdStream.str();
            if (game->isMove(move))
            {
                status = game->ProcessMove(players[onTurn]->getColour(), move);
                if(status == 1)
                {
                    interface->Display("Invalid move!\n");
                    --onTurn;
                }
                continue;
            }
            --onTurn;
            interface->Display("Invalid command\n");
        }
        //std::cerr << "game.start.mainLoop.inf" << std::endl;
        onTurn = 0;
    }
}
int Game::Save(const std::string & fileName)
{
    std::stringstream output;
    output << game->getName() << " " << status << std::endl;
    for(const auto & player : players)
    {
        output << player->Save() << " ";
    }
    output << "- " << onTurn << std::endl;
    output << game->Save();
    return SaveManager::Save(fileName, output.str());
}
std::string Game::Show()
{
    return game->State() + "\nEnter a command:\n";
}
