//
// Created by teodor on 07.05.22.
//

#include "Knight.h"

std::shared_ptr<Piece> Knight::CreateInstance()
{
    return std::make_shared<Knight>(*this);
}