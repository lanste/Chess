//
// Created by teodor on 08.05.22.
//

#include "Game.h"

Game::Game(const std::shared_ptr<Interface> & ui) : interface(ui)
{

}
int Game::Start()
{
    return 0;
}
Game::Game(const std::shared_ptr<Interface> & ui, const std::shared_ptr<Board> & game)
{

}
int Game::Initialize(const std::shared_ptr<Interface> & ui, const std::shared_ptr<Board> & board,
        const std::vector<std::shared_ptr<Player>> & p)
{

    return 0;
}
