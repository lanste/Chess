//
// Created by teodor on 15.05.22.
//

#include "SaveManager.h"

bool SaveManager::Save(const std::string & filename, const std::string & data)
{
    if (not fs::exists(saveFolder))
    {
        fs::create_directory(saveFolder);
    }
    std::fstream fin;
    fin.open(saveFolder + "/" + filename + saveExtension, std::fstream::out);
    if(!fin.is_open())
        return false;
    fin.write(data.c_str(),data.size());
    if(fin.fail())
        return false;
    fin.close();
    return true;
}
bool SaveManager::Load(const std::string & filename, std::vector<std::string> & data)
{
    std::string datapoint;
    if (not fs::exists(saveFolder))
        return false;
    std::fstream fin;
    fin.open(saveFolder + "/" + filename + saveExtension, std::fstream::in);
    if(!fin.is_open())
        return false;
    while(true)
    {
        fin >> datapoint;
        if(fin.fail())
        {
            if(fin.eof())
                break;
            else
            {
                data.clear();
                return false;
            }
        }
        data.push_back(datapoint);
    }
    fin.close();
    return true;
}
std::vector<std::pair<time_t,std::string>> SaveManager::List()
{
    std::vector<std::pair<time_t,std::string>> output;
    std::multimap<time_t, std::string, std::greater<>> helper;
    if (not fs::exists(saveFolder))
        return output;
    for (const auto & elem: fs::directory_iterator(saveFolder))
    {
        if(not elem.is_regular_file() || elem.path().extension() != saveExtension)
            continue;
        const auto time = elem.last_write_time();
        const auto t = to_time_t(time);
        helper.emplace(t, elem.path().stem());
    }
    for(const auto & fData : helper)
    {
        output.emplace_back(fData);
    }
    return output;
}

// https://stackoverflow.com/questions/61030383/how-to-convert-stdfilesystemfile-time-type-to-time
// Converts filesystem timestamp to usable timestamp
template<typename TP>
std::time_t SaveManager::to_time_t(TP tp)
{
    using namespace std::chrono;
    auto sctp = time_point_cast<system_clock::duration>(tp - TP::clock::now()
                                                        + system_clock::now());
    return system_clock::to_time_t(sctp);
}
