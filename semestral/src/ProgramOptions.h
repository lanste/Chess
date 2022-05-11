/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include <string>
#include <vector>
#include <set>
#include <memory>

#include "UI/UIManager.h"
#include "UI/ITerminal.h"

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
        void ReadOptions(int argCnt, char ** args);
        static std::unique_ptr<UIManager> GetInterface();
    protected:
        int argumentCount;
        std::vector<std::string> arguments;
        std::set<std::string> validOptions;
        std::unique_ptr<UIManager> interface;
};