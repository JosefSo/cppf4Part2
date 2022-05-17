#include "Captain.hpp"

namespace coup
{
    void Captain::block(Player &player){
        if (this->getGame()->Players.size() < 3){
            throw std::runtime_error("THe game need at least 3 players");
        }
        if (player.getlastCommand() == "income"){
            throw std::runtime_error("You can't block income() command");
        }
        //player.addBalance(-1);
        
    }
    void Captain::steal(Player &player){
        // if (player.coins() < 2){
        //      throw std::runtime_error("Not enough money on balance of other player");
        // }
        if (this->getName() != this->getGame()->turn()){
            throw std::runtime_error("it is turn "+ this->getGame()->turn());
        }
        if (player.coins() == 1){
            player.addBalance(-1);
            this->addBalance(1);
            // save the player
            this->getGame()->addCaptainSteal(&player, 1);
        }
        if (player.coins() >= 2){
            player.addBalance(-2);
            this->addBalance(2);
            // save the player
            this->getGame()->addCaptainSteal(&player, 2); 
        }
        // if (player.getlastCommand() != "block"){
        //     player.addBalance(-2);
        //     this->addBalance(2);
        //     // save the player
        //     this->getGame()->addCaptainSteal(&player);       
        // }

        // go next turn
        this->getGame()->nexTurn();
    }
    string Captain::role(){
        return "Captain";
    }
}