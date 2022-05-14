//
// Created by teodor on 08.05.22.
//

#include "MainMenu.h"

#include <sstream>

/**
 * Sets contents of the menu
 */
MainMenu::MainMenu(const std::shared_ptr<UIManager> & ui) : interface(ui)
{
    dimensions.width = 20; // arbitrary values ?todo resizable?
                            // may not be actually used
    dimensions.height = 5; // increasing height does nothing
    header = "Main menu";
    menuOptions.emplace_back("Start Game");
    menuOptions.emplace_back("Load Game");
    menuOptions.emplace_back("Exit");

    commands.emplace("0", std::make_shared<StartGameCmd>(interface));
    commands.emplace("1", std::make_shared<LoadGameCmd>());
    commands.emplace("2", std::make_shared<ExitCmd>());
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Passes object data to interface
 * @param interface to pass to
 * @return 0 on success
 */
int MainMenu::Show()
{
    std::string output;
    for (size_t h = 0; h < dimensions.height; ++h) // number of rows
    {
        switch (h)
        {
            case 0:
                output.append(createHeader());
                break;
            case 1:
                output.append(emptyLine());
                break;
            case 2:
                output.append(createOptions());
                h += menuOptions.size();
                break;
            default:
                break;
        }
    }
    output.append(emptyLine());
    output.append(createPrompt());
    interface->Display(output);
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * Creates title of the menu based on dimensions saved in the class
 * @return string containing header
 */
std::string MainMenu::createHeader() const
{
    std::string output;
    //size_t currW = dimensions.width;
    size_t wDiff = dimensions.width - header.size();
    size_t rightW = 0;
    if(wDiff <= 0)
    {
        return header;
    }
    if(wDiff % 2)
    {
        rightW = 1;
       --wDiff;
    }
    rightW += wDiff / 2;
    size_t leftW  = wDiff / 2;
    for(size_t i = 0; i < leftW; ++i)
    {
        output.append(" ");
    }
    output.append(header);
    for(size_t i = 0; i < rightW; ++i)
    {
        output.append(" ");
    }
    return output;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * Creates table with available options todo variable dimensions (maybe)
 * @return string containing all menu options
 */
std::string MainMenu::createOptions() const
{
    //std::string output;
    std::stringstream oss;
    size_t size = menuOptions.size();
    for(size_t op = 0; op < size; ++op)
    {
        oss << "\n" << op << ") " << menuOptions[op];
    }
    return oss.str();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::string MainMenu::emptyLine() const
{
    return "\n" + std::string( dimensions.width, ' ' );
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::string MainMenu::createPrompt()
{
    std::stringstream oss;
    oss << "\nChoose menu option [0-" << menuOptions.size() - 1 << "]:\n";
    return oss.str();
}
int MainMenu::ExecCommand(const std::string & command)
{
    const auto cmd = commands.find(command);
    if(cmd == commands.end())
        return 1;
    return cmd->second->Execute();
}
