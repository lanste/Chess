//
// Created by teodor on 14.05.22.
//

#include "LaunchGameCmd.h"

LaunchGameCmd::LaunchGameCmd(const std::shared_ptr<Interface> & ui) : interface(ui)
{
    game = Game(interface);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int LaunchGameCmd::Execute()
{
    while(true)
    {
        std::string command;
        game.Start();
        interface->Display("DEBUG: game started");
        interface->Receive(command);
    }
}
