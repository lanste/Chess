/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */
#include "Application.h"

Application::Application(const ProgramOptions & options)
{
    interface = ProgramOptions::GetInterface();
}

int Application::Run()
{
    while(true)
    {
        mainMenu->Show(interface); // game is started from the mainMenu class
        break;
    }
    return 0;
}