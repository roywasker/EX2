#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "card.hpp"

namespace ariel {
    class Player {
    public:
        Player();
        Player(std::string name);
        std::string getname();
        int stacksize();
        int cardesTaken();
    private:
        std::string name_;
        int stacksize_;
        int cardesTaken_;
    };
}
#endif //PLAYER_HPP
