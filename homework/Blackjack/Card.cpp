#include <cstring>
#include "Card.h"


Card::Card()
{
    strcpy(color, " ");
    strcpy(power, " ");
    serialNum = nullptr;
//    ++unique;
}


Card::Card(const char* col, const char* pow, const char* serial)
{
    strcpy(this->color, col);
    strcpy(this->power, pow);

    this->serialNum = new char[strlen(serial)+1];
    strcpy(this->serialNum, serial);
//    ++unique;
}


Card::Card(const Card& other)
{
    copy(other);
//    ++unique;
}


int Card::cardToPoint()const
{
    if (strcmp(power, "2") == 0)
        return 2;
    else if (strcmp(power, "3") == 0)
        return 3;
    else if (strcmp(power, "4") == 0)
        return 4;
    else if (strcmp(power, "5") == 0)
        return 5;
    else if (strcmp(power, "6") == 0)
        return 6;
    else if (strcmp(power, "7") == 0)
        return 7;
    else if (strcmp(power, "8") == 0)
        return 8;
    else if (strcmp(power, "9") == 0)
        return 9;
    else if (strcmp(power, "10") == 0 || strcmp(power, "K") == 0
        || strcmp(power, "J") == 0 || strcmp(power, "Q") == 0)
        return 10;
    else if (strcmp(power, "A") == 0)
        return 11;// TODO: if(sbora im stane nad 21, Asoto stava 1)
    else return -1;
}


void Card::copy(const Card& other)
{
    strcpy(this->color, other.color);//static array
    strcpy(this->power, other.power);//static array
    for (int i=0; i < strlen(other.getSerialNum()+1); i++)
    { 
        this->serialNum = new char[strlen(other.getSerialNum())];//dynamic array
        strcpy(this->serialNum, other.getSerialNum());
    }
}


void Card::clear()
{
    delete[] this->serialNum;
    this->serialNum = nullptr;
}


void Card::print()
{
    std::cout << "*" << this->power << "* " << this->color << "\n";
}


Card::~Card()
{
    clear();
}


std::ostream& operator<<(std::ostream& os, const Card& card)
{
    std::cout << "*" << card.getPower() << "* " << card.getColor();
    return os;
}
//da iztriq print()