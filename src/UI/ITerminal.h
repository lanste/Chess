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
        std::shared_ptr<Interface> Create() override;
        void Display(const std::string & message) override;
        void Display(const char & message) override;
        bool Receive(std::string & command) override;
        bool ReceiveLine(std::string & command) override;
        void EmptyLine();
    protected:
        std::istream & input;
        std::ostream & output;
};