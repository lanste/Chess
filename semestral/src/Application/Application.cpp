/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */
#include "Application.h"

Application::Application(const ProgramOptions & options)
{
    mainMenu = std::make_unique<MainMenu>();
    game = Game();
    interface = options.GetInterface();
    cmdManager = CommandManager();
}

int Application::Run()
{
    mainMenu->Show(interface); // basically welcome screen
    while(true)
    {
        std::string command;
        interface->Receive(command);
        if(not cmdManager.Execute(command))
            interface->Display("Unknown command!\n    Try again or use 'help' command"); // suboptimal
        break;
    }
    return 0;
}