//
// Created by teodor on 14.05.22.
//

#include "ChessSetupMenu.h"

ChessSetupMenu::ChessSetupMenu(const std::shared_ptr<Interface> & ui) : interface(ui), header("Chess setup")
{
    execState = 0;

    options.emplace_back("Player");
    options.emplace_back("Easy bot");
    options.emplace_back("Medium bot");
    options.emplace_back("Hard bot");

    pChooser.emplace("0", std::make_shared<LocalPlayer>());
    //pChooser.emplace("3", std::make_shared<OnlinePlayer>());
    pChooser.emplace("1", std::make_shared<AI1>());
    pChooser.emplace("2", std::make_shared<AI2>());
    pChooser.emplace("3", std::make_shared<AI3>());
    commands.emplace("4", std::make_shared<BackCmd>());
}
int ChessSetupMenu::ExecCommand(const std::string & command)
{
    const auto player = pChooser.find(command);
    const auto cmd = commands.find(command);
    if(player != pChooser.end())
    {
        players.push_back(player->second);
        ++execState;
        if(execState == SETUPDONE)
        {
            return LaunchGameCmd(interface, std::make_shared<ClassicalChessBoard>() , players).Execute();
        }
    }
    else if( cmd != commands.end())
    {
        if(execState == CHOOSEP2)
        {
            --execState;
            return CONTINUE;
        }
        return cmd->second->Execute();
    }
    else
        return 0;
    return CONTINUE;
}
int ChessSetupMenu::Show()
{
    createHeader();
    createSubHeader();
    emptyLine();
    createContent();
    emptyLine();
    createPrompt();
    return 0;
}
void ChessSetupMenu::createHeader()
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

void ChessSetupMenu::createContent()
{
    std::stringstream oss;
    int cnt = 0;
    for(const auto & elem : options)
    {
        oss << "\n" << cnt << ") " << elem;
        if(cnt == 0)
            oss << execState + 1;
        ++cnt;
    }
    oss << "\n\n" << options.size() << ") Back";
    interface->Display(oss.str());
}

void ChessSetupMenu::createSubHeader()
{
    std::stringstream oss;
    oss << "\nChoose ";
    if(execState)
        oss << "black";
    else
        oss << "white";
    oss << " player";
    interface->Display(oss.str());
}
void ChessSetupMenu::createPrompt()
{
    std::stringstream oss;
    oss << "\nChoose player [0-" << options.size() - 1 << "]:\n";
    interface->Display(oss.str());
}
