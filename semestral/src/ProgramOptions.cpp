//
// Created by teodor on 08.05.22.
//


#include "ProgramOptions.h"
#include "UI/ITerminal.h"
#include "UI/UIManager.h"

ProgramOptions::ProgramOptions() : argumentCount(0)
{
    validOptions.emplace("-t");
    validOptions.emplace("--terminal");
}
std::unique_ptr<UIManager> ProgramOptions::GetInterface()
{
    std::unique_ptr<UIManager> null(nullptr);
    return null;
}
void ProgramOptions::ReadOptions(int argCnt, char ** args)
{
    argumentCount = argCnt;
    if(argumentCount == 0)
    {
        std::cout << "Graphical interface not yet implemented.\n Use option -t for terminal interface" << std::endl;
    }
    else for(size_t i = 1; i < argumentCount; ++i)
    {
        std::string option = args[i];
        auto result = validOptions.find(option);
        if(result == validOptions.end())
            throw std::invalid_argument("Option \"" + option + "\" doesn't exist"); // todo manage better
        arguments.emplace_back(option);
    }
    int counter = 0;
    for(const auto & option : arguments)
    {
        switch(counter)
        {
            case 0:
                if(option == "-t" || option == "--terminal")
                {
                    ITerminal iTerm;
                    interface = iTerm.Create();
                }
                break;
            case 1:
                std::cout << "placeholder - unknown option" << std::endl;
                break;
            default:
                std::cout << "placeholder - too much options" << std::endl;
                break;
        }
        ++counter;
    }
}
