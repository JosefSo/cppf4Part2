#include "Player.hpp"

namespace coup{

    class Contessa : public Player{
    private:

    public:
        Contessa(Game &game, string name):Player(game, name){ }
        //~Contessa();

        string role();
        void block(Player player);
    };
}