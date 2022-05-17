#include "Duke.hpp"

namespace coup
{
    void Duke::block(Player &player){
        if (this->getGame()->Players.size() < 3){
            throw std::runtime_error("THe game need at least 3 players");
        }
        if (player.getlastCommand() != "foreign_aid"){
            throw std::runtime_error("Duke can't block command that isn't foreign_aid()");
        }
        player.addBalance(-2);
    }
    void Duke::tax(){
        if (this->getName() != this->getGame()->turn()){
            throw std::runtime_error("it is turn "+ this->getGame()->turn());
        }
        this->addBalance(3);
        // go next turn
        this->getGame()->nexTurn();
    }
    string Duke::role(){
        return "Duke";
    }
}