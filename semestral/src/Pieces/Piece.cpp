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
