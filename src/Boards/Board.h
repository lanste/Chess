/*
 * Teodor Lansky <lanskteo@fit.cvut.cz>
 */

#pragma once

#include "../Utility//ChessMove.h"
//#include "../Players/Player.h"

#include <vector>
#include <memory>
#include <sstream>

/**
 * Abstract class
 * Holds current state of the game board
 */
class Board
{
    public:
        explicit Board(const std::string & nName) : name(nName) {}
        /**
         *
         * @param initData vector of strings that the board can use to populate its data structures
         * Intended for loading from save files
         */
        virtual void Initialize(const std::vector<std::string> & initData) = 0;

        /**
         * @return string (todo data structure) used by Interface to show state of the game
         */
        virtual std::string State() = 0;
        /**
         * @return string that will be written directly to a save file
         */
        virtual std::string Save() = 0;
        virtual std::string getName() {return name;}

        /**
         * Decides whether command received from Interface is valid move on this board
         * @param command
         * @return
         */
        virtual bool isMove(std::string & command) = 0;

        /**
         * @param colour of player who is on turn
         * @param m string command given by player, assumes the command was validated by isMove
         * @return parsed and validated move
         */
        virtual ChessMove ProcessMove(const bool & colour, const std::string & m) = 0;

        /**
         *
         * @param move parsed by ProcessMove
         * @return true if execution was successful
         */
        virtual int ExecuteMove(const ChessMove & move) = 0;

        /**
         * @return string passable to interface that states which player has won
         * @example classical chess has two players - black, white. class Game sees that it works with 2 players, but doesn't know that one is white and the other is black. That's why this method is necessary
         * @param colour
         *
         */
        virtual std::string announceWinner(const bool & colour) = 0;
    private:
        std::string name;
        //virtual ostream & print(ostream & os) const = 0;
};
