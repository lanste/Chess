//
// Created by teodor on 07.05.22.
//

#include "Rook.h"

std::shared_ptr<Piece> Rook::CreateInstance()
{
    return std::make_shared<Rook>(*this);
}