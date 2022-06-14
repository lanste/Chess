/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Player.h"

/**
 * Placeholder for possible online multiplayer
 * Implementation not planned for semestral presentation
 */
class OnlinePlayer : public Player
{
    public:
        OnlinePlayer() = default;
        //std::string makeTurn(std::shared_ptr<Interface> interface) override;
};