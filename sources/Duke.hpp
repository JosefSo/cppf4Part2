#include "Player.hpp"

namespace coup{

    class Duke : public Player{
    private:

    public:
        Duke(Game &game, string name) : Player(game, name){ }
        //~Duke();

        void tax();
        string role();
        //void income();
        void block(Player &player);
        
    };
}
