#include "doctest.h"
#include <stdexcept>
#include "sources/card.hpp"
#include "sources/Game.hpp"
#include "sources/Player.hpp"

using namespace ariel;

TEST_CASE("card initialization"){
    card card1;
    CHECK_EQ(card1.getcardtype(), "diamonds");
    CHECK_EQ(card1.getcardname(), "king");
    card card2("10", "hearts");
    CHECK_EQ(card2.getcardtype(), "hearts");
    CHECK_EQ(card2.getcardname(), "10");
}

TEST_CASE("with card is higher"){
    card card1("10", "hearts");
    card card2("king", "hearts");
    CHECK(card1.compare(card2));
}

TEST_CASE("game initialization") {
    Player player1("roy");
    Player player2;
    Game game(player1, player2);
    CHECK_EQ(player1.stacksize(), 26);
    CHECK_EQ(player2.stacksize(), 26);
    CHECK_EQ(player1.cardesTaken(), 0);
    CHECK_EQ(player2.cardesTaken(), 0);
}

TEST_CASE("check that not throw error"){
    Player player1("roy");
    Player player2;
    Game game(player1, player2);
    CHECK_NOTHROW(game.playTurn());
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.playAll());
    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printLog());
}

TEST_CASE("check that player cant play against himself"){
    Player player1("roy");
    Game game(player1, player1);
    CHECK_THROWS(game.playTurn());
    CHECK_THROWS(game.playAll());
}

TEST_CASE("check that in the end of game 2 player have 0 card"){
    Player player1("roy");
    Player player2("bob");
    Game game(player1, player2);
    game.playAll();
    CHECK_EQ(player1.stacksize(), 0);
    CHECK_EQ(player2.stacksize(), 0);
    CHECK_EQ(player1.cardesTaken()+player2.cardesTaken(), 52);
}

TEST_CASE("check that player not play in 2 different game"){
    Player player1("roy");
    Player player2("bob");
    Player player3;
    Game game1(player1, player2);
    Game game2(player1, player3);
    game1.playTurn();
    CHECK_THROWS(game2.playTurn());
}

TEST_CASE("check print winner before game end (play one turn)"){
    Player player1("roy");
    Player player2("bob");
    Game game(player1, player2);
    game.playTurn();
    CHECK_THROWS(game.printWiner());
}

TEST_CASE("create wrong card"){
    card card1("11", "hearts");
    CHECK_THROWS(card1.getcardname());
}

TEST_CASE("player initialization") {
    Player player1("roy");
    CHECK_EQ(player1.stacksize(), 0);
    CHECK_EQ(player1.cardesTaken(), 0);
    Player player2;
    CHECK_EQ(player2.getname(), "guest");
    CHECK_EQ(player2.stacksize(), 0);
    CHECK_EQ(player2.cardesTaken(), 0);
}