//
// Created by teodor on 07.05.22.
//

#include "King.h"

//King::King(const bool & col) : Piece('K',col)
//{
//
//}

std::shared_ptr<Piece> King::CreateInstance()
{
    return std::make_shared<King>(*this);
}

void King::Save(std::ofstream os)
{
    return;
}
