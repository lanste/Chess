//
// Created by teodor on 08.05.22.
//

#include "Game.h"

Game::Game(const std::shared_ptr<UIManager> & ui) : interface(ui)
{

}
int Game::Start()
{
    return 0;
}
Game::Game(const std::shared_ptr<UIManager> & ui, const std::shared_ptr<Board> & game)
{

}
