//
// Created by teodor on 16.05.22.
//

#include "LoadGameCmd.h"

LoadGameCmd::LoadGameCmd(const std::shared_ptr<Interface> & ui, const std::pair<time_t, std::string> & save) :
                        interface(ui), saveName(save.second)
{

}


int LoadGameCmd::Execute()
{
    std::string command;
    std::vector<std::string> data;

    SaveManager::Load(saveName, data);
    if(parseData(data))
        return 1;
    return 0;
}

int LoadGameCmd::parseData(const std::vector<std::string> & data)
{
    if(data.size() == 0)
    {
        interface->Display("Loading failed unexpectedly.\n");
        return 1;
    }
    if(data[0] != "Chess") // placeholder todo ability to load different games
    {
        interface->Display("Invalid save file.\n");
        return 1;
    }

    try{status = std::stoi(data[1]);}
    catch (std::invalid_argument & e){
        interface->Display("Invalid save file.\n");
        return 1;
    }
    for(auto& i : {2,3})
    {
        std::string playerId = data[i];
        if(playerId == "loc") //local player
            players.push_back(std::make_shared<LocalPlayer>());
        else if(playerId == "ai1")
            players.push_back(std::make_shared<AI1>());
        else if(playerId == "ai2")
            players.push_back(std::make_shared<AI2>());
        else if(playerId == "ai2")
            players.push_back(std::make_shared<AI3>());
        //if(playerId == "onl") //local player
          //  players.push_back(std::make_shared<LocalPlayer>())
    }
    players[0]->setColour(false);
    players[1]->setColour(true);
    turn = std::stoi(data[5]);

    std::vector<std::string> boardData(data.begin() + 6, data.end());
    board = std::make_shared<ClassicalChessBoard>(true);
    board->Initialize(boardData);

    LaunchGameCmd loaded(interface,board, status, players, turn);
    loaded.Execute();
    return 0;
}

