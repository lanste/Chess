//
// Created by teodor on 12.05.22.
//

#include "MenuStartOptionCmd.h"

MenuStartOptionCmd::MenuStartOptionCmd(const std::shared_ptr<Interface> & ui) : interface(ui)
{

}

int MenuStartOptionCmd::Execute()
{
    std::string command;
    StartGameMenu menu(interface);
    while(true)
    {
        menu.Show();
        interface->Receive(command);
        if(menu.ExecCommand(command))
            return 0;
    }
}
