//
// Created by teodor on 08.05.22.
//

#include "Application.h"
#include "ProgramOptions.h"

int main (int argc, char* *argv)
{
    ProgramOptions options(argc, argv);
    Application(options).Run();
    return 0;
}
