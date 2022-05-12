//
// Created by teodor on 12.05.22.
//

#include "CommandManager.h"

CommandManager::CommandManager()
{
    commands.emplace("test", std::make_shared<StartGameCmd>());
}
int CommandManager::Execute(std::string command)
{
    const auto cmd = commands.find(command);
    if(cmd == commands.end())
        return false;
    return cmd->second->Execute();
}
