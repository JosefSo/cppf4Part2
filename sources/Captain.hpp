#include "Player.hpp"

namespace coup{

    class Captain : public Player{
    private:

    public:
        Captain(Game &game, string name):Player(game, name){ }
        //~Captain();

        string role();
        void steal(Player &player);
        void block(Player &player);
    };
}