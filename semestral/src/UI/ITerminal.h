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
        ITerminal();
        ~ITerminal() = default;
        std::shared_ptr<UIManager> Create();
        void Display(const std::string & message);
        bool Receive(std::string & command);
        void EmptyLine();
    protected:
        std::istream & input;
        std::ostream & output;
};