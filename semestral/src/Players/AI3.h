/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Player.h"
/**
 * Class reperesenting hard AI player
 */

class AI3 : public Player
{
    public:
        AI3() = default;
        std::string makeTurn(std::shared_ptr<Interface> interface) override;
};
