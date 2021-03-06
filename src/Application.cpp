/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */
#include "Application.h"

std::string SaveManager::saveFolder = "saves";
std::string SaveManager::saveExtension = ".save";

Application::Application(const ProgramOptions & options) : interface(options.GetInterface()), mainMenu(MainMenu(options.GetInterface()))
{
}

int Application::Run()
{
    int status = 0;
    interface->Display("\033c"); // initial screen clearing

    while(true)
    {
        mainMenu.Show();
        std::string command;
        interface->Receive(command);
        status = mainMenu.ExecCommand(command);

        if(status == EXITCODE)
            return 0;
        if(status == 1)
        {
            interface->Display("Unknown command!\n");
        }
    }
}