#include "Ambassador.hpp"



namespace coup{
    void Ambassador::transfer(Player &from, Player &to){
        if (from.coins() < 1){
            throw std::runtime_error("not enough coins to transfer");
        }
        from.addBalance(-1);
        to.addBalance(1);
        // go next turn
        this->getGame()->nexTurn();
    }
    string Ambassador::role(){
        return "Ambassador";
    }
    void Ambassador::block(Player &player){

        // if(strcmp(player.role(),  "Captain")){
        //     throw std::runtime_error("You can block only Captain!");
        // }

        player.addBalance(-2);
        this->getGame()->returnCaptainSteal(); // call the func that returns coins
    }
}