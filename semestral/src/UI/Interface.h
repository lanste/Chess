/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include <string>
#include <memory>

/**
 * abstract class representing user interfaces
 */
class Interface
{
    public:
        Interface() = default;
        ~Interface() = default;
        virtual std::shared_ptr<Interface> Create() = 0;
        virtual void Display(const std::string & message) = 0;
        virtual bool Receive(std::string & command) = 0;
    protected:

};