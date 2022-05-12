//
// Created by teodor on 08.05.22.
//

/**
 * MASTER TODO LIST
 * todo: fix author note in every class
 * todo: comment base classes
 */

#include "Application/Application.h"
#include "Application/ProgramOptions.h"

#include <string>


int main (int argc, char* *argv)
{
    ProgramOptions options;

    if(options.ReadOptions(argc, argv))
        return 0;
    Application(options).Run();
    return 0;
}
