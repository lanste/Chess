//
// Created by teodor on 08.05.22.
//

#include "MainMenu.h"

#include <sstream>

/**
 * Sets contents of the menu
 */
MainMenu::MainMenu()
{
    dimensions.width = 20; // arbitrary values ?todo resizable?
                            // may not be actually used
    dimensions.height = 5; // increasing height does nothing
    header = "Main menu";
    menuOptions.emplace_back("Start Game");
    menuOptions.emplace_back("Load Game");
    menuOptions.emplace_back("Exit");
}
/**
 * Passes object data to interface
 * @param interface to pass to
 * @return 0 on succes
 */
int MainMenu::Show(const std::shared_ptr<UIManager> & interface)
{
    std::string output;
    for (int h = 0; h < dimensions.height; ++h) // number of rows
    {
        switch (h)
        {
            case 0:
                output.append(createHeader());
                break;
            case 1:
                output.append(emptyLine());
                break;
            case 2:
                output.append(createOptions());
                h += menuOptions.size();
                break;
            default:
                break;
        }
    }
    interface->Display(output);
    return 0;
}
std::string MainMenu::createHeader() const
{
    std::string output;
    int currW = dimensions.width;
    int wDiff = dimensions.width - header.size();
    if(wDiff <= 0)
        return header;
    int rightW = 0;
    if(wDiff % 2)
    {
        rightW = 1;
       --wDiff;
    }
    rightW += wDiff / 2;
    int leftW  = wDiff / 2;
    for(int i = 0; i < leftW; ++i)
    {
        output.append(" ");
    }
    output.append(header);
    for(int i = 0; i < rightW; ++i)
    {
        output.append(" ");
    }
    return output;
}

std::string MainMenu::createOptions() const
{
    //std::string output;
    std::stringstream is;
    size_t size = menuOptions.size();
    for(size_t op = 0; op < size; ++op)
    {
        is << "\n" << op << ") " << menuOptions[op];
    }
    return is.str();
}

std::string MainMenu::emptyLine() const
{
    return "\n" + std::string( dimensions.width, ' ' );
}