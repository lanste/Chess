//
// Created by teodor on 14.05.22.
//

#include "GameSetupMenu.h"

GameSetupMenu::GameSetupMenu(const std::shared_ptr<UIManager> & ui) : interface(ui), header("Chess setup")
{
    status = 0;

    options.emplace_back("Player", std::make_shared<LocalPlayer>());
    options.emplace_back("Easy bot", std::make_shared<AI1>());
    options.emplace_back("Medium bot", std::make_shared<AI2>());
    options.emplace_back("Hard bot", std::make_shared<AI3>());


    commands.emplace("0", std::make_shared<ChoosePlayerCmd>());
    commands.emplace("1", std::make_shared<ChoosePlayerCmd>());
    commands.emplace("2", std::make_shared<ChoosePlayerCmd>());
    commands.emplace("3", std::make_shared<ChoosePlayerCmd>());
    commands.emplace("4", std::make_shared<BackCmd>());
    //commands.emplace("3", std::make_shared<ChoosePlayerCmd>());
}
int GameSetupMenu::Show()
{
    createHeader();
    createSubHeader();
    emptyLine();
    createContent();
    emptyLine();
    createPrompt();
    return 0;
}
int GameSetupMenu::ExecCommand(const std::string & command)
{
    return 0;
}
void GameSetupMenu::createHeader()
{
#define WIDTH 20 //todo redesign
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

void GameSetupMenu::createContent()
{
    std::stringstream oss;
    int cnt = 0;
    for(const auto & elem : options)
    {
        oss << "\n" << cnt << ") " << elem.first;
        if(cnt == 0 && status == 0)
            oss << status + 1;
        ++cnt;
    }
    interface->Display(oss.str());
}

void GameSetupMenu::createSubHeader()
{
    std::stringstream oss;
    oss << "\nChoose ";
    if(status)
        oss << "black";
    else
        oss << "white";
    oss << " player";
    interface->Display(oss.str());
}
void GameSetupMenu::createPrompt()
{
    std::stringstream oss;
    oss << "\nChoose player [0-" << options.size() - 1 << "]:\n";
    interface->Display(oss.str());
}
