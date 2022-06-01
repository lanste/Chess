/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "../UI/Interface.h"
#include "../UI/ITerminal.h"

#include <memory>

/**
 * Player abstract class
 */
class Player
{
    public:
        Player() = default;
        explicit Player(const bool & nColour) : colour(nColour) {}
        virtual std::string makeTurn(std::shared_ptr<Interface> interface) = 0;
        virtual void setColour(bool nColour){
            colour = nColour;
        }
        virtual bool getColour(){
            return colour;}
    protected:
        bool colour;

};

