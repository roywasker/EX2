#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include <string>
namespace ariel{
    class Game {
    public:
        Game();
        Game(Player player1, Player player2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
    private:
        Player player1_;
        Player player2_;
    };
}
#endif //GAME_HPP
