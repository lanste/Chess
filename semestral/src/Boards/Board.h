/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include <memory>
#include <vector>

#include "../Players/Player.h"

/**
 * Abstract class
 * Holds current state of the game board
 */
class Board
{
    public:
        Board() = default;
    private:
        //virtual ostream & print(ostream & os) const = 0;
};
