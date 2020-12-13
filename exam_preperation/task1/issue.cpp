#include <cstring>

#include "issue.hpp"
#define MAX_INPUT 1000

Issue::Issue()
        : title(NULL)
        , price((float) 0)
        , quantity(0u)
{       }

Issue::Issue(const Issue& other)
{
        copy(other);
}

const Issue& Issue::operator=(const Issue& other)
{
        if(this != &other)
        {
                clear();
                copy(other);
        }
        return *this;
}

Issue::~Issue()
{
        clear();
}

void Issue::copy(const Issue& other) 
{
        this->title = new char[strlen(other.title) + 1];
        strcpy(this->title, other.title);
        this->price = other.price;
        this->quantity = other.quantity;
}

void Issue::clear() 
{
        if(this->title)
        {
                delete[] this->title;
                this->title = NULL;
        }
}

const char* Issue::get_title() const
{
        return this->title;
}

float Issue::get_price() const
{
        return this->price;
}

unsigned int Issue::get_quantity() const
{
        return this->quantity;
}

void Issue::set_title(const char *_title) 
{
        if(this->title)
        {
                delete[] this->title;
                this->title = NULL;
        }

        this->title = new char[strlen(_title) + 1];
        strcpy(this->title, _title);
}

void Issue::set_price(float _price) 
{
        this->price = _price;
}

void Issue::set_quantity(unsigned int _quantity) 
{
        this->quantity = _quantity;
}

std::ostream& operator<<(std::ostream& os, const Issue& obj)
{
        std::cout << obj.title << " " << obj.price << " " << obj.quantity;

        return os;
}

std::istream& operator>>(std::istream& is, Issue& obj) 
{
        char _title[MAX_INPUT];
        std::cin >> _title;
        obj.set_title(_title);
        std::cin >> obj.price;
        std::cin >> obj.quantity;
        
        return is;
}

