//
// Created by teodor on 08.05.22.
//

#include "MainMenu.h"

/**
 * Sets contents of the menu
 */
MainMenu::MainMenu()
{
    dimensions.height = 10; // arbitrary values ?todo resizable?
    dimensions.width = 10; // may not be actually used
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
int MainMenu::Show(const std::unique_ptr<UIManager> & interface)
{
    std::string output;
    for (int h = 0; h < dimensions.height; ++h) // number of rows
    {
        switch (h)
        {
            case 0:
                output.append(createHeader());
                break;
        }
    }

    return 0;
}
std::string MainMenu::createHeader() const
{
    std::string output;
    int currW = dimensions.width;
    int wDiff = header.size() - dimensions.width;
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
