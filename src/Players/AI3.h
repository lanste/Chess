/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Player.h"
/**
 * Class representing hard AI player
 */

class AI3 : public Player
{
    public:
        AI3();
        std::string Save() override;
        std::string makeTurn(std::shared_ptr<Interface> interface) override;
};
