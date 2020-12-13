#include <iostream>
#include <cassert>
#include "Stack.hpp"

const int EMPTY_STACK = -1;
size_t INITIAL_CAPACITY = 16;

ResizingStack::ResizingStack()
{
        top = EMPTY_STACK;
        capacity = INITIAL_CAPACITY;
        data = new TYPE[INITIAL_CAPACITY];
}

bool ResizingStack::full() const
{
        return top == capacity - 1;
}

bool ResizingStack::empty() const
{
        return top == EMPTY_STACK;
}

void ResizingStack::push(const TYPE& a)
{
        if (full())
                resize();

        data[++top] = a;
}

int ResizingStack::pop() 
{
        assert(!empty()); 
        return data[top--];
}

int ResizingStack::peek() const 
{
        assert(!empty()); 
        return data[top];
}

void ResizingStack::resize() 
{
        unsigned newCapacity = capacity * 2;
        TYPE *old_data = data;
        data = new TYPE[newCapacity];
        for(size_t i = 0; i < capacity; ++i)
                data[i] = old_data[i];

        capacity = newCapacity;
        delete[] old_data;
}

ResizingStack::~ResizingStack()
{
        clear();
}

ResizingStack::ResizingStack(ResizingStack const& other)
{
    copy(other);
}

ResizingStack& ResizingStack::operator=(const ResizingStack& other) 
{
    if (this != &other)
    {
            clear();
            copy(other);
    }
    return *this;
}

void ResizingStack::copy(const ResizingStack& other)
{
        this->top = other.top;
        this->capacity = other.capacity;
        this->data = new TYPE[other.capacity];
        for(size_t i = 0; i < other.capacity; ++i)
                this->data[i] = other.data[i];
}

void ResizingStack::clear()
{
        delete[] this->data;
        top = 0;
        capacity = 0;
}