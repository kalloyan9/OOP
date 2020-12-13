#ifndef _SUBSCRIPTION
#define _SUBSCRIPTION
#include <cstring>
#include <stdlib.h>

#include "issue.hpp"
#define DEFAULT_CAPACITY 2


class Subscription 
{
private:
        Issue *arr;
        size_t capacity;
        size_t size;
        

public:
        //big four
        Subscription();
        Subscription(const Subscription& other);
        Subscription& operator=(const Subscription& other);
        ~Subscription();

        //operators
        friend Subscription& operator+=(Subscription& lhs, Issue& rhs);
        Issue& operator[](size_t i);

        //helpers
        void copy(const Subscription& other);
        void clear();
        void resize(); //current capacity x2

};

#endif