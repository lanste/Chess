/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Player.h"

/**
 * Class reperesenting easy AI player
 */
class AI1 : public Player
{
    public:
        AI1() = default;
        std::string makeTurn(std::shared_ptr<Interface> interface) override;
};