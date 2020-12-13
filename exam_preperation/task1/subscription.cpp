#include "subscription.hpp"

Subscription::Subscription() 
        : arr(new Issue[DEFAULT_CAPACITY])
        , capacity(DEFAULT_CAPACITY)
        , size(0)
{       }

Subscription::Subscription(const Subscription& other) 
{
        copy(other);        
}

Subscription& Subscription::operator=(const Subscription& other) 
{
        if(this != &other)
        {
                clear();
                copy(other);
        }
        
        return *this;
}

void Subscription::copy(const Subscription& other) 
{
        this->capacity = other.capacity;
        this->size = other.size;
        this->arr = new Issue[other.capacity];
        for (size_t i = 0; i < other.size; i++)
                this->arr[i] = other.arr[i];
}

void Subscription::clear() 
{
        delete[] this->arr;
}

void Subscription::resize() 
{
        size_t new_capacity = this->capacity * 2;
        Issue *new_arr = new Issue[new_capacity];
        for(size_t i = 0; i < this->size; ++i)
                new_arr[i] = this->arr[i];

        delete[] this->arr;
        this->capacity = new_capacity;
        this->arr = new_arr;
}

Issue& Subscription::operator[](size_t i)
{
        if(i <= this->size)
                return this->arr[i];
}

Subscription::~Subscription() 
{
        clear();
}

Subscription& operator+=(Subscription& lhs, Issue& rhs) 
{
        if(lhs.size >= lhs.capacity)
                lhs.resize();
        
        lhs.arr[lhs.size] = rhs;
        lhs.size++;
}
