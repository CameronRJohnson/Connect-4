#include "player.h"

Player::Player() : name("Unnamed"), id(0) {}

Player::Player(const std::string& name, int id) : name(name), id(id) {}

std::string Player::getName() const { return name; }
int Player::getId() const { return id; }