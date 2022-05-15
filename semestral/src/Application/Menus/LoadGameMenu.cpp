//
// Created by teodor on 15.05.22.
//

#include "LoadGameMenu.h"

LoadGameMenu::LoadGameMenu(const std::shared_ptr<Interface> & ui) : interface(ui), saves(SaveManager())
{
    header = "Load game";
    // LoadGameCmd is called dynamically based on number of existing saves
    saveList = saves.List();
    commands.emplace(std::to_string(saveList.size()), std::make_shared<BackCmd>());
}
int LoadGameMenu::Show()
{
    createHeader();
    emptyLine();
    createContent();
    emptyLine();
    createPrompt();
    return 0;
}
int LoadGameMenu::ExecCommand(const std::string & command)
{
    Game newGame;
    int choice = 0;
    const auto cmd = commands.find(command);
    if(cmd == commands.end())
        return 1;
    try
    {
        choice = std::stoi(command);
    }
    catch(const std::invalid_argument & e)
    {
        interface->Display("Unknown command"); // todo this is bad
        return 2;
    }
    catch(const std::out_of_range & e)
    {
        interface->Display("Unknown command"); // this is bad
        return 2;
    }
    if(choice > saveList.size())
    {
        interface->Display("Unknown command"); // this is bad
        return 2;
    }
    else if(choice == saveList.size())
        return cmd->second->Execute();

    saves.Load(saveList[choice], newGame);
    newGame.Start();
    return 1;
}
void LoadGameMenu::createHeader()
{
#define WIDTH 20;
    std::string output;
    size_t size = header.size();
    size_t wDiff = WIDTH - size;
    size_t leftW, rightW;
    if (wDiff % 2)
    {
        leftW = (wDiff - 1) / 2 + 1;
        rightW = (wDiff - 1) / 2;
    }
    else
        leftW = (rightW = wDiff / 2);
    std::string leftPad(leftW, ' ');
    std::string rightPad(rightW, ' ');
    output.append(leftPad + header + rightPad);
    interface->Display(output);
}
void LoadGameMenu::createContent()
{
    std::stringstream oss;
    int cnt = 0;
    if(saveList.empty())
    {
        oss << "\nYou have no saves.";
    }
    else for(const auto elem : saveList)
    {
        oss << "\n" << cnt << ") " << elem;
        ++cnt;
    }
    oss << "\n" << cnt << ") " << "Back";
    interface->Display(oss.str());
}
void LoadGameMenu::createPrompt()
{
    std::stringstream oss;
    size_t optCnt = 0;
    if(not saveList.empty())
    {
        optCnt = saves.List().size();
        oss << "\nChoose save to load [0-" << optCnt << "]";
    }
    else
    {
        oss << "\nChoose 0 or type \"Back\"";
    }
    interface->Display(oss.str());
}
void LoadGameMenu::emptyLine()
{
    interface->Display("\n" + std::string( 20, ' ' ));
}
