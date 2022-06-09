#include "Piece.h"

#include <iostream>

Piece::Piece()
{

}
void Piece::Print(std::ostream & os)
{
    char out = symbol;
    if(colour)
        out = tolower(out);
    os << out;
}
bool Piece::getColour()
{
    return colour;
}
char Piece::Save()
{
    if(colour)
        return tolower(symbol);
    return symbol;
}
coordinates Piece::getPosition()
{
    return position;
}
void Piece::updatePosition(const coordinates & newPos)
{
    pastPosition = position;
    position = newPos;
}
void Piece::revertPosition()
{
        position = pastPosition;
}


