#pragma once
#include <cstring>
#include "Card.h"


class Deck;
class Deck
{   
public:
    //big four
    Deck();
    Deck(int currentCapacity);
    Deck(int currentCapacity, const char* serialDeckNumber);
    Deck(const Card& other);
    Deck& operator=(const Deck& other);
    ~Deck();

    //methods
    Card* draw();//purvata karta otiva nai otdolu i se returnva
    bool swap(int idx1, int idx2);//razmenq 2 karti, ako sa s validni indexi za testeto
    size_t suit_count(const char* color) const;
    size_t rank_count(const char* power) const;  
    void permutation();
    
    //helper
    size_t find_count(const char* a[], const char* searched) const;
    unsigned getCurrentCapacity()const { return currentCapacity;  }//new

private:
    void copy(const Deck& other);
    void clear();
    
    Card** sequenceOfCards;
    char* serialDeckNumber;
    int maximumCapacity;
    int currentCapacity;
    static int uniqueierForCard;
};

