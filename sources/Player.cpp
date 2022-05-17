#include "Player.hpp"



namespace coup{
    const int ten = 10;
    const int seven = 7;
    const int three = 3;
    const int two = 2;
    
    Player::Player(Game &game, string name){
        if (game.gameStarted){
            throw std::runtime_error("Game already started");
        }
        this->game = &game;
        this->name = std::move(name);
        this->game->addPlayer(*this);
        this->lastCommand = "";
        this->balance = 0;
        this->isAlive = true;
        this->cantBlockByContessa = false;
        if (game.first){
            this->myTurn = true;
            game.first = false;
        }
        else{
            this->myTurn = false;
        }

    }
    Player::~Player(){}

    string Player::getlastCommand(){
        return this->lastCommand;
    }
    string Player::getName(){
        return this->name;
    }
    Game* Player::getGame(){
        return this->game;
    }


    void Player::setLastCommand(string command){
        this->lastCommand = std::move(command);
    }
    void Player::addBalance(int to){
        this->balance+=to;
    }


    void Player::income(){
        if (this->getGame()->Players.size() < three){
            throw std::runtime_error("THe game need at least 3 players");
        }
        if (this->name != this->game->turn()){
            throw std::runtime_error("it is turn "+ this->getGame()->turn());
        }
        this->getGame()->gameStarted = true;
        ++this->balance;
        this->lastCommand = "income";

        this->game->nexTurn(); 
    }
    int Player::coins() const{
        int ans = this->balance;
        return ans;
    }

    void Player::foreign_aid(){
        if (this->coins() >= ten){
            throw std::runtime_error("You can not take more then 10 coins");
        }
        if (this->getGame()->Players.size() < three){
            throw std::runtime_error("THe game need at least 3 players");
        }
        if (this->name != this->game->turn()){
            throw std::runtime_error("it is turn "+ this->getGame()->turn());
        }
        this->balance += two;
        this->lastCommand = "foreign_aid";
        this->getGame()->nexTurn();
    }

    void Player::coup(Player &player){
        if (!this->isAlive){
            throw std::runtime_error("player "+this->getName()+" is dead");
        }
        if (this->getGame()->Players.size() < three){
            throw std::runtime_error("THe game need at least 3 players");
        }
        if (this->name != this->game->turn()){
            throw std::runtime_error("it is turn "+ this->getGame()->turn());
        }
        if (this->balance < seven){
            throw std::runtime_error("not enough coins to coup");
        }
        bool found = false;
        unsigned int size = this->game->Players.size();
        for (unsigned int i = 0; i < size; i++){
            if (!player.isAlive){
                throw std::runtime_error("player "+player.getName()+" is dead");
            }
            if (player.getName() == (this->getGame()->Players.at(i)->getName()))
            {
                this->getGame()->saveCoupPlayer(&player); // save to queue before erase
                this->getGame()->Players.at(i)->isAlive = false;
                this->lastCommand = "coup";
                player.isAlive = false;
                this->getGame()->nexTurn();
                this->addBalance(-seven);
                return;
            }
        }
        this->lastCommand = "coup";
        this->getGame()->nexTurn();
        throw std::runtime_error("Player (to earse) not found");
    }

    string Player::role(){
        return this->name;
    }
    



}