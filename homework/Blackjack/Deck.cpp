#include "Deck.h"
#include <iostream>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <cmath>       /* floor */
#include "static_globals.hpp"
using namespace static_globals;
Deck::Deck() : Deck(52, "Default")
{int uniqueierForCard = 0;}

Deck::Deck(int newCurrentCapacity) : Deck(newCurrentCapacity, " ")
{
    permutation();
}

Deck::Deck(int currentCapacity, const char* serialDeckNumber)
{
    int uniqueierForCard = 0;
    maximumCapacity = currentCapacity;
    this->currentCapacity = currentCapacity;
    sequenceOfCards = new Card* [maximumCapacity];
    this->serialDeckNumber = new char[strlen(serialDeckNumber)+1];
    strcpy(this->serialDeckNumber, serialDeckNumber);
    
    for (int i=0; i < currentCapacity; i++)
    {
        char number[MAX_SIZE_SERIAL_NUM];
        strcpy(number, serialDeckNumber);        
        ++uniqueierForCard;
        Card* new_card = new Card(colors[i%4], powers[(i/4)%13], number + uniqueierForCard);
//        new_card->print();
        sequenceOfCards[i] = new_card;
    }
}


Deck& Deck::operator=(const Deck& other)
{
    if (this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}


Deck::~Deck()
{
    clear();
}

size_t Deck::find_count(const char* a[], const char* searched) const
{
    size_t count = 0;
    int i=0;
    while(i<currentCapacity)
    {
        if(strcmp(a[i], searched) ==0)
            ++count;
        ++i;
    }
    return count;
}


size_t Deck::suit_count(const char* color) const
{
    return find_count(colors, color);
}


size_t Deck::rank_count(const char* power) const
{
    return find_count(powers, power);
}


void Deck::copy(const Deck& other)
{
    this->maximumCapacity = other.maximumCapacity;
    this->currentCapacity = other.currentCapacity;
    sequenceOfCards = new Card * [other.maximumCapacity];
    this->serialDeckNumber = new char[strlen(other.serialDeckNumber) + 1];
    strcpy(this->serialDeckNumber, other.serialDeckNumber);
}


void Deck::clear()
{
    delete[] sequenceOfCards;
    sequenceOfCards = nullptr;
    delete[] serialDeckNumber;
    serialDeckNumber = nullptr;
}


Card* Deck::draw()//purvata karta otiva nai otdolu i se returnva
{
    Card* buffer = this->sequenceOfCards[this->currentCapacity-1];//copy constructor to copy the first card
    for(int i = this->currentCapacity-1; i>0; --i)
        this->sequenceOfCards[i] = this->sequenceOfCards[i-1];

    this->sequenceOfCards[0] = buffer;
    return buffer;
}


bool Deck::swap(int idx1, int idx2)//razmenq 2 karti, ako sa s validni indexi za testeto
{
    if( (idx1 >= 0 && idx1 <= this->currentCapacity) 
        && (idx2 >= 0 && idx2 <= this->currentCapacity) )
    {
        Card* buffer = this->sequenceOfCards[idx1];
        this->sequenceOfCards[idx1] = this->sequenceOfCards[idx2];
        this->sequenceOfCards[idx2] = buffer;
        return true;
    }
    else
        return false;
}


void Deck::permutation()
{
    srand(time(NULL));
    int maxRep = floor((this->currentCapacity-1)/52 + 1);
    Deck helper(52, "HELPER");
    const int size = 52;
    int used [size] = { 0 };
    int index;
    int numCards = 0;
    for (int i = 0; i < size; ++i)
    {
        do
        {
            index = rand() % size;
            this->sequenceOfCards[i] = helper.sequenceOfCards[index];
        } while (used[index]);
        ++used[index];
        ++numCards;
    }
    while (numCards < currentCapacity)
    {
        index = rand() % size;
        if (used[index] < maxRep)
        {
            this->sequenceOfCards[numCards] = helper.sequenceOfCards[index];
            ++numCards;
            ++used[index];
        }
    }
    std::cout << numCards << ":" << std::endl;
    for (int i = 0; i < size; ++i)
        std::cout << used[i] << ": " << *this->sequenceOfCards[i] << std::endl;
    std::cout << "- - - - -\n";
}

