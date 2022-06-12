/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */


#include "ProgramOptions.h"
#include "ITerminal.h"
#include "Interface.h"

ProgramOptions::ProgramOptions() : argumentCount(0)
{
    validOptions.emplace("-t");
    validOptions.emplace("--terminal");
}
std::shared_ptr<Interface> ProgramOptions::GetInterface() const
{
    return interface->Create();
}
int ProgramOptions::ReadOptions(int argCnt, char ** args)
{
    argumentCount = argCnt;
    if(argumentCount == 1)
    {
        std::cout << "Graphical interface not yet implemented.\n Use option -t for terminal interface" << std::endl;
        return 2;
    }
    else for(int i = 1; i < argumentCount; ++i)
    {
        std::string option = args[i];
        auto result = validOptions.find(option);
        if(result == validOptions.end())
            throw std::invalid_argument("Option \"" + option + "\" doesn't exist.\n Use -h to show available options."); // todo manage better
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
    return 0;
}
