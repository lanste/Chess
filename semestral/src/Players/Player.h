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
        Player(const std::string & nId) : id(nId)
        {}
        explicit Player(const bool & nColour, const std::string & nId) : colour(nColour), id(nId) {}
        virtual std::string makeTurn(std::shared_ptr<Interface> interface) = 0;
        virtual void setColour(int nColour){
            colour = nColour;
        }
        virtual int getColour(){
            return colour;}
        virtual std::string Save() = 0;
    protected:
        int colour;
        std::string id;


};

