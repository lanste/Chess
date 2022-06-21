/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Player.h"

/**
 * Class representing medium AI player
 */
class AI2 : public Player
{
    public:
        AI2();
        std::string makeTurn(std::shared_ptr<Interface> interface) override;
        std::string Save() override;
};



