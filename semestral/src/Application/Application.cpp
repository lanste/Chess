/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */
#include "Application.h"

Application::Application(const ProgramOptions & options)
{
    mainMenu = std::make_unique<MainMenu>();
    game = std::make_unique<Game>();
    interface = options.GetInterface();
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