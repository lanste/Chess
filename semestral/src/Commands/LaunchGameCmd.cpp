//
// Created by teodor on 14.05.22.
//

#include "LaunchGameCmd.h"

LaunchGameCmd::LaunchGameCmd(const std::shared_ptr<Interface> & ui) : interface(ui)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int LaunchGameCmd::Execute()
{
    while(true)
    {
        std::string command;
        interface->Receive(command);
    }
}
