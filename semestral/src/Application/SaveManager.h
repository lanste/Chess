//
// Created by teodor on 15.05.22.
//

#pragma once

#include "../Application/Game.h"

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <filesystem>

namespace fs = std::filesystem;

class SaveManager
{
    public:
        SaveManager() = default;
        bool Save(const std::string & filename, const Game & data);
        bool Load(const std::string & filename, Game & data);
        std::vector<std::pair<time_t,std::string>> List();
    protected:
        template <typename TP> std::time_t to_time_t(TP tp);

        const std::string saveFolder = "../saves";
        const std::string saveExtension = ".save";
};