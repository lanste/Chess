//
// Created by teodor on 07.05.22.
//

#include "Queen.h"

std::shared_ptr<Piece> Queen::CreateInstance()
{
    return std::make_shared<Queen>(*this);
}