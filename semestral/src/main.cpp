//
// Created by teodor on 08.05.22.
//

/**
 * MASTER TODO LIST
 * todo: fix author note in every class
 * todo: comment base classes
 */


#include "Application.h"
#include "ProgramOptions.h"

int main (int argc, char* *argv)
{
    ProgramOptions options();
    options.ReadOptions(argc, argv);
    Application(options).Run();
    return 0;
}
