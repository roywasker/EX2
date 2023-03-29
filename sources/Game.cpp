#include "Game.hpp"
#include <iostream>

using namespace ariel;

Game::Game() :player1_(Player()), player2_(Player()){}

Game::Game(Player player1, Player player2) :player1_(player1), player2_(player2){}

void Game::playAll() {}

void Game::playTurn() {}

void Game::printLastTurn() {}

void Game::printLog() {}

void Game::printStats() {}

void Game::printWiner() {}