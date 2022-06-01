//
// Created by teodor on 08.05.22.
//

#include "LocalPlayer.h"

LocalPlayer::LocalPlayer() : Player()
{
}
std::string LocalPlayer::makeTurn(std::shared_ptr<Interface> interface)
{
    std::string cmd;
    interface->Receive(cmd);
    return cmd;
}
