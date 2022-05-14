/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */
#include "Application.h"

Application::Application(const ProgramOptions & options) : interface(options.GetInterface()), game(Game(interface))
{
    //cmdManager = CommandManager();
    mainMenu = std::make_unique<MainMenu>(interface);
}

int Application::Run()
{
    int status = 0;
    interface->Display("\033c"); // initial screen clearing
    //  ^^^^ todo function? this would be the only use outside of ITerm class
    while(true)
    {
        mainMenu->Show();
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