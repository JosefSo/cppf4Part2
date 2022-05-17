
#pragma once
#include <iostream>
#include "Game.hpp"
#include <string>
#include <queue>
//#include <stdexcept>

using std::string;
using std::ostream;
using std::istream;
using std::queue;

namespace coup{
    class Game;
    class Player{

    private:
        string name;
        Game* game; //pointer to player's game
        int balance; //coins
        string lastCommand;
        

        
    public:
        bool cantBlockByContessa;
        bool isAlive;
        bool myTurn;
        Player(Game& game, string name);
        ~Player();

        void income();
        int coins() const;
        void foreign_aid();
        virtual void coup(Player &player);
        virtual string role();
        
        string getlastCommand();
        string getName();
        Game* getGame();
        
        void setLastCommand(string command);

        void addBalance(int to);


    };
}
