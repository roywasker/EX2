#include "card.hpp"

#include <string>

using namespace ariel;

card::card(std::string name, std::string type) : name_(name) , type_(type){}

card::card() : name_("king") , type_("diamonds"){}

std::string card::getcardname(){return name_;}

std::string card::getcardtype(){ return type_;}

int card::compare(card card1) {return 0;}