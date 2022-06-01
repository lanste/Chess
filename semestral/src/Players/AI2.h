/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Player.h"

/**
 * Class reperesenting medium AI player
 */
class AI2 : public Player
{
    public:
        AI2() = default;
        std::string makeTurn(std::shared_ptr<Interface> interface) override;
};



