#pragma once
#include <iostream>
#include <vector>
#include <string>
#include<queue>
#include "Player.hpp"
#include<tuple> // for tuple

using std::string;
using std::vector;
using std::queue;
using std::tuple;

namespace coup{
    class Player;

    struct {
        int myNum;
        string myString;
    } myStructure;

    class Game{
        public:
            bool gameStarted;
            bool first;// = true;
            vector<Player*> Players;
            queue<Player*> coupPlayers; //blocked players
            queue<tuple<Player*, int>> captainSteal;

            string turn();
            vector<string> players();
            string winner();

            void nexTurn();

            Game();
            Game(string player);
            ~Game();
            void addPlayer(Player &player);
            void saveCoupPlayer(Player* pl);
            void addCoupPlayer();
            void addCaptainSteal(Player* pl, int q);
            void returnCaptainSteal();

            void getPlayer(string name);



    };
}