//
// Created by teodor on 19.05.22.
//

//#pragma once
//
//#include "../Command.h"
//
//#include "../../Application/Game.h"
//#include "../../Application/SaveManager.h"
//
//class SaveGameCmd : public Command
//{
//    public:
//        SaveGameCmd(const std::string & name, const Game & toSave);
//        SaveGameCmd(const std::string & name);
//        SaveGameCmd(const Game & toSave);
        SaveGameCmd(const std::string & name, const Game* toSave);
//        int Execute() override;
//    protected:
//        std::string fileName;
//        SaveManager manager;
//        Game data;
//};
//

