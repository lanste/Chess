/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "UIManager.h" // base class

#include <string>
#include "iostream"

/**
 * class representing basic terminal ui layer
 */
class ITerminal : public UIManager
{
    public:
        explicit ITerminal();
        void Display(const std::string & message);
        bool Receive(std::string & command);
    protected:
        std::istream & input;
        std::ostream & output;
};