#include "Player.hpp"

namespace coup{

    class Ambassador : public Player{
    private:

    public:
        Ambassador(Game &game, string name):Player(game, name){ }
        //~Ambassador();

        void transfer(Player &from, Player &to);
        string role();
        void block(Player &player);
    };
}