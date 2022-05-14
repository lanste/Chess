//
// Created by teodor on 08.05.22.
//

#include "MainMenu.h"

#include <sstream>
#include <string>

/**
 * Sets contents of the menu
 */
MainMenu::MainMenu(const std::shared_ptr<UIManager> & ui) : interface(ui)
{
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
    createHeader();
    emptyLine();
    createOptions();
    emptyLine();
    createPrompt();
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * Creates title of the menu based on dimensions saved in the class
 * @return string containing header
 */
void MainMenu::createHeader() const
{
#define WIDTH 20 //todo redesign
    std::string output;
    //size_t currW = dimensions.width;
    size_t wDiff = WIDTH - header.size();
    size_t rightW = 0;
    if(wDiff <= 0)
    {
        interface->Display(header);
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
    interface->Display(output);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * Creates table with available options todo variable dimensions (maybe)
 * @return string containing all menu options
 */
void MainMenu::createOptions() const
{
    //std::string output;
    std::stringstream oss;
    size_t size = menuOptions.size();
    for(size_t op = 0; op < size; ++op)
    {
        oss << "\n" << op << ") " << menuOptions[op];
    }
    interface->Display(oss.str());
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MainMenu::createPrompt()
{
    std::stringstream oss;
    oss << "\nChoose menu option [0-" << menuOptions.size() - 1 << "]:\n";
    interface->Display(oss.str());
}
int MainMenu::ExecCommand(const std::string & command)
{
    const auto cmd = commands.find(command);
    if(cmd == commands.end())
        return 1;
    return cmd->second->Execute();
}
