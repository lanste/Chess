//
// Created by teodor on 07.05.22.
//

#include "Bishop.h"

std::shared_ptr<Piece> Bishop::CreateInstance()
{
    return std::make_shared<Bishop>(*this);
}
void Bishop::Print(Interface & interface)
{

}
