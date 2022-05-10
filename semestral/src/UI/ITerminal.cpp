//
// Created by teodor on 08.05.22.
//

#include "ITerminal.h"

ITerminal::ITerminal() : input(std::cin), output(std::cout)
{
}
void ITerminal::Display(const std::string & message)
{

}
bool ITerminal::Receive(std::string & command)
{
    return false;
}