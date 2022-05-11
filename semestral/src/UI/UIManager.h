/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include <string>
#include <memory>

/**
 * abstract class representing user interfaces
 */
class UIManager
{
    public:
        UIManager() = default;
        ~UIManager() = default;
        virtual std::unique_ptr<UIManager> Create() = 0;
        virtual void Display(const std::string & message) = 0;
        virtual bool Receive(std::string & command) = 0;
    protected:

};