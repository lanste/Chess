//
// Created by teodor on 15.05.22.
//

#include "SaveManager.h"

bool SaveManager::Save(std::string filename, const Game & data)
{
    if(not fs::exists(saveFolder))
    {
        fs::create_directory(saveFolder);
    }
    std::fstream fin(filename);
    //fin.open()
    return false;
}
bool SaveManager::Load(std::string filename, Game & data)
{
    if(not fs::exists(saveFolder))
        return false;
    return false;
}
std::vector<std::string> SaveManager::List()
{
    std::vector<std::string> output;
    if(not fs::exists(saveFolder))
        return output;
    for (const auto & elem : fs::directory_iterator(saveFolder))
         output.emplace_back(elem.path().stem());
    return output;
}
