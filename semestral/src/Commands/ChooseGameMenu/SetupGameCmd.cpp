//
// Created by teodor on 13.05.22.
//

#include "SetupGameCmd.h"

SetupGameCmd::SetupGameCmd(const std::shared_ptr<Interface> & ui, const std::shared_ptr<Board> & board) : interface(ui), game(Game(ui, board))
{

}

int SetupGameCmd::Execute()
{
    GameSetupMenu menu(interface);
    while(true)
    {
        std::string command;
        menu.Show();
        interface->Receive(command);
        int status = menu.ExecCommand(command);
        if(status == 1)
            return 0;
    }
    //game.Start();
    //return 0;
}
