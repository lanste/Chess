//
// Created by teodor on 08.05.22.
//

#include "ITerminal.h"

ITerminal::ITerminal() : input(std::cin), output(std::cout)
{
}

std::shared_ptr<UIManager> ITerminal::Create()
{
    return std::make_shared<ITerminal>(*this);
}

void ITerminal::Display(const std::string & message)
{
    output << message;
}
bool ITerminal::Receive(std::string & command)
{
    input >> command;
    if(input.fail())
    {
        command = "";
        return false;
    }
    output << "\033c"; // clear the screen
    return true;
}
