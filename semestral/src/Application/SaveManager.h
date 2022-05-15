//
// Created by teodor on 15.05.22.
//

#pragma once

#include "../Application/Game.h"

#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

class SaveManager
{
    public:
        SaveManager() = default;
        bool Save(std::string filename, const Game & data);
        bool Load(std::string filename, Game & data);
        std::vector<std::string> List();
    protected:
        const std::string saveFolder = "../saves";
};