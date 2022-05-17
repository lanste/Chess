#include "Piece.h"

#include <iostream>

Piece::Piece()
{

}
void Piece::Print(ostream & interface)
{
    char out = symbol;
    if(colour)
        out = tolower(out);
    interface.Display(out);
}
