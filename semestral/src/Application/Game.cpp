//
// Created by teodor on 08.05.22.
//

#include "Game.h"

Game::Game(const std::shared_ptr<Interface> & ui) : interface(ui)
{
    initialized = false;
}
Game::Game(const std::shared_ptr<Interface> & ui, const std::shared_ptr<Board> & board) : interface(ui), game(board)
{
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

    main_loop
    {
        for(const auto & player : players)
        {
            interface->Display(game->State());
            player->makeTurn(game);
            if(status == 420)
                return 1;
        }

    }
}
