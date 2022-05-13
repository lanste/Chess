//
// Created by teodor on 12.05.22.
//

#include "StartGameCmd.h"

StartGameCmd::StartGameCmd(const Game & nGame, const std::shared_ptr<UIManager> & ui) : game(nGame), interface(ui)
{

}

int StartGameCmd::Execute()
{
    std::string command;
    StartGameMenu menu(interface, game);
    while(true)
    {
        menu.Show();
        interface->Receive(command);
        if(menu.ExecCommand(command))
            return 1;
    }
}
