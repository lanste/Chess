//
// Created by teodor on 08.05.22.
//

#include "ITerminal.h"

ITerminal::ITerminal() : input(std::cin), output(std::cout)
{
}

std::shared_ptr<Interface> ITerminal::Create()
{
    return std::make_shared<ITerminal>(*this);
}

void ITerminal::Display(const std::string & message)
{
    output << message;
}
bool ITerminal::ReceiveLine(std::string & command)
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
bool ITerminal::Receive(std::string & command)
{
    command = "empty";
    std::getline(input,command);
    if(input.fail() || command == "empty")
    {
        command = "";
        Display("Error while reading your message! Try again please.");
        return false;
    }
    output << "\033c"; // clear the screen
    return true;
}
void ITerminal::EmptyLine()
{
    output << "\n";
}
void ITerminal::Display(const char & message)
{
    output << message;
}
