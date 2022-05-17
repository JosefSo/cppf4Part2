#include "Game.hpp"



namespace coup{
    const int six = 6;
    
    // constructor
    Game::Game() {this->first = true; this->gameStarted = false;}
    Game::~Game() {}

    vector<string> Game::players() {
        vector<string> alivePlayers;
        for(Player* pl : this->Players){
            if(pl->isAlive){
                alivePlayers.insert(alivePlayers.begin() ,pl->getName());
                //std::cout<<pl->getName() << " " << pl->myTurn;
            }
        }
        return alivePlayers;
    }


    void Game::addPlayer(Player &player){
        //this->PlayersNames.insert(PlayersNames.begin() ,name);
        if(this->Players.size() == six){
            throw std::runtime_error("The game if full");
        }
        this->Players.insert(Players.begin(), &player);
    }
    void Game::saveCoupPlayer(Player* pl){
        this->coupPlayers.push(pl);
    }
    void Game::addCoupPlayer(){
        this->coupPlayers.back()->isAlive = true;
        this->coupPlayers.pop(); // remove

    }

    void Game::addCaptainSteal(Player* pl, int q){
        tuple<Player*, int> tup;
        tup = std::make_tuple(pl, q);
        this->captainSteal.push(tup);
    }
    void Game::returnCaptainSteal(){
        tuple<Player*, int> tup;
        tup = this->captainSteal.back();

        std::get<0>(tup)->addBalance(std::get<1>(tup));
        this->captainSteal.pop(); // remove
    }


    string Game::turn(){
        string name;
        for(Player* pl : this->Players){
            if (pl->myTurn){
                name = pl->getName();
            }
        }
        return name;
    }

    void Game::nexTurn(){
        // string name = this->PlayersNames.back();
        // this->PlayersNames.pop_back();
        // addPlayer(name);
        bool found = false;
        unsigned long index = 0;
        unsigned long size = this->Players.size();
        for(unsigned long i = size-1; i >= 0; --i)
        {
            vector<string> playerss = this->players();
            if (playerss.size() == 1){
                //std::cout << "playerss.size() == 1 "<<"\n";
                return;
            }
            if(this->Players.at(i)->myTurn)
            {
                index = i;
                //std::cout << "index: "<<index;
                while(true){
                    
                    if (i >= 0 && i != index && this->Players.at(i)->isAlive){
                        this->Players.at(i)->myTurn = true;
                        this->Players.at(index)->myTurn = false;
                        // std::cout<<"turn: "<<this->Players.at(i)->getName()<<" at index "<< i <<"\n";
                        return;
                    }
                    if (i <= 0){
                        i=size-1;
                        continue;
                    }
                    --i;
                }
            }
	    }
    }

    string Game::winner(){
        if (!this->gameStarted){
            throw std::runtime_error("no winner: game didn't started");
        }
        unsigned int size = this->Players.size();
        int count = 0;
        string winner;
        for (unsigned int i = 0; i < size; i++){
            if (this->Players.at(i)->isAlive){
                count++;
                winner = this->Players.at(i)->getName();
            }
        }
        if (count > 1){
            throw std::runtime_error("No winner!");
        }
        return winner;

    }
    
}