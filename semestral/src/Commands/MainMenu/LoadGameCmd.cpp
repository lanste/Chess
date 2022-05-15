//
// Created by teodor on 12.05.22.
//

#include "LoadGameCmd.h"

LoadGameCmd::LoadGameCmd(const std::shared_ptr<Interface> & ui) : interface(ui)
{

}
int LoadGameCmd::Execute()
{
    LoadGameMenu menu(interface);
    while(true)
    {
        std::string command;
        menu.Show();
        interface->Receive(command);
        int status = menu.ExecCommand(command);
        if(status)
            return 0; // todo placeholder
    }
    return 0;
}
