#include "Player.hpp"

namespace coup{

    class Assassin : public Player{
    private:

    public:
        
        Assassin(Game &game, string name):Player(game, name){ }
        //~Assassin();

        void coup(Player &player);
        string role();
    };
}