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
    int status = 0;
    while(true)
    {
        mainMenu->Show(interface); // basically welcome screen
        std::string command;
        interface->Receive(command);
        status = mainMenu->ExecCommand(command);


        //status = cmdManager.Execute(command, "main");
        if(status == EXITCODE)
            return 0;
        if(status == 1)
        {
            interface->Display("Unknown command!\n    Try again or use 'help' command"); // suboptimal
        }
    }
    return 0;
}