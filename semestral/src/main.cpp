//
// Created by teodor on 08.05.22.
//

/**
 * MASTER TODO LIST
 * todo: fix author note in every class
 * todo: comment base classes
 */


#include <string>
#include "Application.h"
#include "ProgramOptions.h"

int readOptions(int argc, char* *argv)
{

    for(int i = 1; i < argc; ++i)
    {
        std::string arg(argv[i]);
        if(arg == "-t" || arg == "--terminal")
            return 0;
    }
    return 1;
}

int main (int argc, char* *argv)
{
    /*/
    if(readOptions(argc, argv))
    {
        std::cerr << "graphical UI is not yet implemented" << std::endl;
    }

    /*/
    // todo future
    ProgramOptions options;
    options.ReadOptions(argc, argv);
    Application(options).Run();
    /*/
    return 0;
}
