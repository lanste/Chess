/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */
#include "Application.h"

Application::Application(const ProgramOptions & options)
{
    interface = options.GetInterface();
}

int Application::Run()
{
    while(true)
    {
        menu->Show(); // game is started from the menu class
        break;
    }
    return 0;
}