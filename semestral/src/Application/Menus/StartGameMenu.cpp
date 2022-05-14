//
// Created by teodor on 12.05.22.
//


#include "StartGameMenu.h"

StartGameMenu::StartGameMenu(const std::shared_ptr<Interface> & ui) : interface(ui), header("Choose game")
{
    options.emplace_back("Chess", std::make_shared<ClassicalChessBoard>());
    //options.emplace_back("Checkers", std::make_shared<CheckersBoard>()); // different game example
    options.emplace_back(">Coming soon<", nullptr);
    options.emplace_back("Back", nullptr);

//    size_t cnt = 0; // todo polymorphic
//    for(const auto & elem : options)
//    {
//        commands.emplace(std::to_string(cnt++), std::make_shared<Command>(options[0].second));
//    }

    commands.emplace("0", std::make_shared<SetupGameCmd>(interface, options[0].second));
    commands.emplace("1", std::make_shared<ComingSoonCmd>(interface));
    commands.emplace("2", std::make_shared<BackCmd>());
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int StartGameMenu::Show()
{
    std::string command;
    createHeader();
    emptyLine();
    createContent();
    emptyLine();
    createPrompt();
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void StartGameMenu::createHeader()
{
#define WIDTH 20
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void StartGameMenu::createContent()
{
    std::stringstream output;
    size_t opCnt = options.size();
    for (size_t i = 0; i < opCnt; ++i)
    {
        output << '\n' << i << ") " << options[i].first;
    }
    interface->Display(output.str());
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void StartGameMenu::createPrompt()
{
    interface->Display("\nChoose a game: \n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * Executes commands available to this menu
 * @param command
 * @return 1 on succesful execution - leads to exiting endless loop one level above
 *         0 if passed command doesn't exist - endless loop continues
 */
int StartGameMenu::ExecCommand(const std::string & command)
{
    const auto cmd = commands.find(command);
    if(cmd == commands.end())
        return 0;
    return cmd->second->Execute();
}
