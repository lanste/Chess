//
// Created by teodor on 15.05.22.
//

#pragma once



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
        static bool Save(const std::string & filename, const std::string & data);
        static bool Load(const std::string & filename, std::string & data);
        std::vector<std::pair<time_t,std::string>> List();
        static std::string saveFolder;
        static std::string saveExtension;
    protected:
        template <typename TP> std::time_t to_time_t(TP tp);


};