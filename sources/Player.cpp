#include "Player.hpp"

using namespace ariel;

Player::Player(std::string name) : name_(name), stacksize_(0), cardesTaken_(0) {}

Player::Player() : name_("guest"), stacksize_(0), cardesTaken_(0) {}

std::string Player::getname(){return name_;}

int Player::stacksize(){return stacksize_;}

int Player::cardesTaken(){return cardesTaken_;}