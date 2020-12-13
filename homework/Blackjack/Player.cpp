#include <iostream>
#include <cstring>
#include "Player.h"

Player::Player()
{
    name = nullptr;
    years = 0;
    wins = 0;
    winRate = 0;
    currentPoints = 0;
}


Player::Player(const char* n, int y, unsigned w, float wr, unsigned cp)
    :name(new char[strlen(n)+1])
    ,years(y)
    ,wins(w)
    ,winRate(wr)
    ,currentPoints(cp)
{
    strcpy(this->name, n);
}


Player::Player(const Player& other)
{
    copy(other);
}


Player& Player::operator=(const Player& other)
{
    if (this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}

    
Player::~Player()
{
    clear();
}


void Player::setCurrentPoints(unsigned currentPoints)
{
    this->currentPoints = currentPoints;
}


void Player::copy(const Player& other)
{
    this->name = new char[strlen(other.name)+1];
    strcpy(this->name, other.name);
    this->years = other.years;
    this->wins = other.wins;
    this->winRate = other.winRate;
    this->currentPoints = other.currentPoints;
}


void Player::clear()
{
    delete[] name;
    name = nullptr;
}


std::ostream& operator<<(std::ostream& os, const Player& player)
{
    os << player.name << '/' << player.years << '/' << player.wins << '/'
        <<player.winRate << '/';
    return os;
}