#include "Assassin.hpp"

namespace coup
{
    const int seven = 7;
    const int three = 3;
    void Assassin::coup(Player &player){
        if (!this->isAlive){
            throw std::runtime_error("player "+this->getName()+" is dead");
        }
        if (this->coins() < 3){
            throw std::runtime_error("not enough coins to coup");
        }
        bool found = false;
        int size = this->getGame()->Players.size();
        for (unsigned int i = 0; i < size; i++){
            if (!player.isAlive){
                throw std::runtime_error("player "+player.getName()+" is dead");
            }
            if (player.getName() == (this->getGame()->Players.at(i)->getName()))
            {
                // save to queue before erase
                this->getGame()->saveCoupPlayer(&player); 
                // coup from the game
                this->getGame()->Players.at(i)->isAlive = false;
                this->setLastCommand("coup");
                player.isAlive = false;
                this->getGame()->nexTurn();
                if (this->coins() >= seven){
                    this->addBalance(-seven);
                    this->cantBlockByContessa = true;
                }
                else{
                    this->addBalance(-three);
                    this->cantBlockByContessa = false;
                }
                return;
            }
        }
        this->setLastCommand("coup");
        this->getGame()->nexTurn();
        throw std::runtime_error("Player (to earse) not found");
    }

    string Assassin::role(){
        string name = "Assassin";
        return name;
    }
}