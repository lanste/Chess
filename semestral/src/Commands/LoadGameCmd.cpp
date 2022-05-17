//
// Created by teodor on 16.05.22.
//

#include "LoadGameCmd.h"

LoadGameCmd::LoadGameCmd(const std::shared_ptr<Interface> & ui, const std::pair<time_t, std::string> & save) : interface(ui)
{

}


int LoadGameCmd::Execute()
{
    std::string command;
    while(true)
    {
        interface->Display("DEBUG::Game loaded");
        interface->Receive(command);
    }
    return 0;
}
