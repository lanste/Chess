/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "../Players/Player.h"

#include <vector>
#include <memory>
#include <sstream>

/**
 * Abstract class
 * Holds current state of the game board
 */
class Board
{
    public:
        Board() = default;
        virtual void Initialize() = 0;
        virtual std::string State() = 0;
        virtual int ProcessMove(const std::stringstream & m) = 0;
        virtual bool isMove(std::stringstream & command) = 0;
    private:
        //virtual ostream & print(ostream & os) const = 0;
};
