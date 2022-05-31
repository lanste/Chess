//
// Created by teodor on 08.05.22.
//

#include "Game.h"


Game::Game(const std::shared_ptr<Interface> & ui) : interface(ui)
{
    initialized = false;
    status = 0;
}
Game::Game(const std::shared_ptr<Interface> & ui, const std::shared_ptr<Board> & board, const std::vector<std::shared_ptr<Player>> & p) : interface(ui), game(board), players(p)
{
    //commands.emplace("save", std::make_shared<SaveGameCmd>(this));
    commands.emplace("exit", std::make_shared<BackCmd>());
    //commands.emplace("help", std::make_shared<GameHelpCmd>(interface));
    commands.emplace("save", nullptr);
    //commands.emplace("exit", std::make_shared<>());


    initialized = true;
    status = 0;
}
int Game::Initialize(const std::shared_ptr<Interface> & ui, const std::shared_ptr<Board> & board,
        const std::vector<std::shared_ptr<Player>> & p)
{
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
    size_t turns = players.size();
    main_loop
    {
        for(size_t i = 0; i < turns; ++i)
        {
            interface->Display(Show());
            interface->Receive(command);
            /*
             * commands here can have arguments, delimited by space
             * -> load whole line to stream and decompose word by word
            */
            std::stringstream cmdStream(command);
            //std::cerr << cmdStream.str();
            cmdStream >> command;
            const auto cmd = commands.find(command);

            if (cmd != commands.end() && cmd->second != nullptr)
            {
                if (command == "save") // this is stupid todo fix
                {
                    cmdStream >> argument;
                    Save(argument);
                    //status = saveManager.Save(argument, *this);
                }
                status = cmd->second->Execute();
                if(status)
                    return 1;
            }

            std::string move = cmdStream.str();
            if (game->ifMoveParse(move))
            {
                status = game->ProcessMove(/*players[i],*/ move);
                if(status == 1)
                {
                    interface->Display("Invalid move!\n");
                }
                continue;
            }

            interface->Display("Invalid command\n");
        }

    }
}
int Game::Save(const std::string & fileName)
{
//    std::stringstream output;
//    for(const auto & player : players)
//    {
//        player->Save();
//    }
    //game.Save();
    return 0;
}
std::string Game::Show()
{
    return game->State() + "\nEnter a command:\n";
}
