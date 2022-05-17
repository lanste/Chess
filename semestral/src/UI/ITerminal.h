/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "Interface.h" // base class

#include <string>
#include "iostream"

/**
 * class representing basic terminal ui layer
 */
class ITerminal : public Interface
{
    public:
        ITerminal();
        ~ITerminal() = default;
        std::shared_ptr<Interface> Create();
        void Display(const std::string & message);
        bool Receive(std::string & command);
        bool ReceiveLine(std::string & command);
        void EmptyLine();
    protected:
        std::istream & input;
        std::ostream & output;
};