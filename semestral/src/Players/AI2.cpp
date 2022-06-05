//
// Created by teodor on 08.05.22.
//

#include "AI2.h"

AI2::AI2() : Player("ai2")
{}

std::string AI2::makeTurn(std::shared_ptr<Interface> interface)
{
    return std::string();
}
std::string AI2::Save()
{
    return id;
}
