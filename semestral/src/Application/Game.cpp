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
    interface->Display(game->State());

    std::string command;
    std::string argument;
    size_t turns = players.size();
    main_loop
    {
        for(size_t i = 0; i < turns; ++i)
        {
            interface->Display(game->State());
            interface->ReceiveLine(command);
            /*
             * commands here can have arguments, delimited by space
             * -> load whole line to stream and decompose word by word
            */
            std::stringstream cmdStream(command);
            cmdStream >> command;
            const auto cmd = commands.find(command);

            if(cmd != commands.end() && cmd->second != nullptr)
            {
                if(command == "save") // this is stupid todo fix
                {
                    cmdStream >> argument;

                    //status = saveManager.Save(argument, *this);
                }
                status = cmd->second->Execute();
            }


            if(game->isMove(cmdStream))
                status = game->ProcessMove(/*players[i],*/ cmdStream);
            interface->Display("Invalid command\n");

            if(status == 420)
                return 1;
        }

    }
}
int Game::Save(const std::string & fileName)
{
    std::stringstream output;
    for(const auto & player : players)
    {
        //player->Save();
    }
    //game.Save();
    return 0;
}
