//
// Created by teodor on 30.05.22.
//

#pragma once

/**
 * Utility struct representing position on a board
 */
struct coordinates
{
    coordinates() = default;
    coordinates(const int & newX, const int & newY) : x(newX), y(newY) {}
    int x,y;
    coordinates operator + (const coordinates & rop) const
    {
        return {x + rop.x, y + rop.y};
    }
    coordinates operator - (const coordinates & rop) const
    {
        return {x - rop.x, y - rop.y};
    }
    bool operator == (const coordinates & rop) const
    {
        return x == rop.x && y == rop.y;
    }
};