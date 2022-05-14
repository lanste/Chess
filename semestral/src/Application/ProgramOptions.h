/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include <string>
#include <vector>
#include <set>
#include <memory>

#include "../UI/Interface.h"
#include "../UI/ITerminal.h"

/**
 * Helper class
 * processes options given by user
 * - which interface will be used
 * - todo etc
 */
class ProgramOptions
{
    public:
        explicit ProgramOptions();
        [[nodiscard]] int ReadOptions(int argCnt, char ** args);
        std::shared_ptr<Interface> GetInterface() const;
    protected:
        int argumentCount;
        std::vector<std::string> arguments;
        std::set<std::string> validOptions;
        std::shared_ptr<Interface> interface;
};