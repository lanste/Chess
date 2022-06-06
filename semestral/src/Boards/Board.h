/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

//#include "../Players/Player.h"

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
        Board(const std::string & nName) : name(nName) {}
        virtual void Initialize(const std::vector<std::string> & initData) = 0;
        virtual std::string State() = 0;
        virtual std::string Save() = 0;
        virtual std::string getName() {return name;}
        virtual int ProcessMove(const bool & colour, const std::string & m) = 0;
        virtual bool isMove(std::string & command) = 0;
    private:
        std::string name;
        //virtual ostream & print(ostream & os) const = 0;
};
