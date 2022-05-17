#include "Contessa.hpp"

namespace coup
{
    void Contessa::block(Player player){

        // if(strcmp(player.role(),  "Assassin")){
        //     throw std::runtime_error("You can block only Assassin!");
        // }
        if (player.getlastCommand() == "foreign_aid"){
            throw std::runtime_error("Contessa can't block foreign_aid() command");
        }
        if (player.cantBlockByContessa){
            throw std::runtime_error("Can't block because assassin couped with 7coins");
        }
        this->getGame()->addCoupPlayer(); // return coup player to the game

        
    }
    string Contessa::role(){
        return "Contessa";
    }
}