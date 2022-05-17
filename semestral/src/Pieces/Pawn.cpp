//
// Created by teodor on 07.05.22.
//

#include "Pawn.h"

std::shared_ptr<Piece> Pawn::CreateInstance()
{
    return std::make_shared<Pawn>(*this);
}
void Pawn::Save(std::ofstream os)
{

}
