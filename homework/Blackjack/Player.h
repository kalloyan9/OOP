#pragma once
#include<iostream>
class Player
{
public:
    Player();
    Player(const char* n, int y, unsigned w, float wr, unsigned cp);
    Player(const Player& other);
    Player& operator=(const Player& other);
    ~Player();

    void setPoints(unsigned points);
    void setWins(unsigned wins);
    void setCurrentPoints(unsigned currentPoints);


    char* getName() const { return name; }
    unsigned getWins()const { return wins; }
    unsigned getCurrentPoints() const { return currentPoints; }
    
    
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    
private:
    void clear();
    void copy(const Player& other);


    char* name;
    int years;
    unsigned wins;
    float winRate;
    unsigned currentPoints;
};

