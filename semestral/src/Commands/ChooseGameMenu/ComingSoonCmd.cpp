//
// Created by teodor on 13.05.22.
//

#include "ComingSoonCmd.h"

ComingSoonCmd::ComingSoonCmd(const std::shared_ptr<UIManager> & ui) : interface(ui)
{

}

int ComingSoonCmd::Execute()
{
    interface->Display("Nothing here\n\n");
    return 0;
}
