//
// Created by teodor on 08.05.22.
//


#include "ProgramOptions.h"
#include "UI/ITerminal.h"
#include "UI/UIManager.h"

ProgramOptions::ProgramOptions()
{
    validOptions.emplace("-t");
    validOptions.emplace("--terminal");
}
std::shared_ptr<UIManager> ProgramOptions::GetInterface() const
{
    return nullptr;
}
void ProgramOptions::ReadOptions(int argCnt, char ** args)
{
    argumentCount = argCnt;
    if(argumentCount == 0)
    {
        ITerminal iTerm;
        interface = std::make_shared<UIManager>(iTerm);
    }
    else for(size_t i = 1; i < argumentCount; ++i)
    {
        std::string option = args[i];
        auto result = validOptions.find(option);
        if(result == validOptions.end())
            throw std::invalid_argument("Option \"" + option + "\" doesn't exist"); // todo manage better
        arguments.emplace_back(option);
    }
}
