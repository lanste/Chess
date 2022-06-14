//
// Created by teodor on 08.05.22.
//

#include "AI3.h"

AI3::AI3() : Player("ai3")
{

}
std::string AI3::makeTurn(std::shared_ptr<Interface> interface)
{
    return std::string();
}
std::string AI3::Save()
{
    return id;
}
