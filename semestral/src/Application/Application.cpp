/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */
#include "Application.h"

Application::Application(const ProgramOptions & options) : interface(options.GetInterface()), game(Game(interface))
{
    cmdManager = CommandManager();
    mainMenu = std::make_unique<MainMenu>(interface, game);
}

int Application::Run()
{
    int status = 0;
    while(true)
    {
        mainMenu->Show(); // basically welcome screen
        std::string command;
        interface->Receive(command);
        status = mainMenu->ExecCommand(command);

        if(status == EXITCODE)
            return 0;
        if(status == 1)
        {
            interface->Display("Unknown command!\n    Try again or use 'help' command\n\n"); // suboptimal
        }
    }
}