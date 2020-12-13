#pragma once
#include <iostream>
#include "static_globals.hpp"
#include<iostream>
using namespace static_globals;

class Card
{
public:
    Card();
    Card(const char* col, const char* pow, const char* serial);
    Card(const Card& other);
    ~Card();    

    void print();
    int cardToPoint()const;
    const char* getColor()const { return this->color; }
    const char* getPower()const { return this->power; }
    const char* getSerialNum()const { return this->serialNum; }
    
    
    friend std::ostream& operator<<(std::ostream& os, const Card& card);

private:
    void clear();
    void copy(const Card& other);

    //data
    char color[MAX_COLORS];
    char power[MAX_POWER];
    char* serialNum;
};
