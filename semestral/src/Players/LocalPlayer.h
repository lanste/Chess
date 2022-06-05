/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Player.h" // base class

/**
 * class representing a player using the machine
 * where the game is currently running
 */
class LocalPlayer : public Player
{
    public:
        LocalPlayer();
        std::string makeTurn(std::shared_ptr<Interface> interface) override;
        std::string Save() override;
    protected:
};