#ifndef __RSTACK_HPP
#define __RSTACK_HPP
#define TYPE int

class ResizingStack
{
private:
        TYPE *data;
        int top; //for EMPTY_STACK = -1
        size_t capacity;
        bool full() const;
        void resize();
        void copy(const ResizingStack& other);
        void clear();
public:
        ResizingStack();
        ResizingStack(const ResizingStack& other);
        ResizingStack& operator=(const ResizingStack& other);
        ~ResizingStack();
        
        bool empty() const;
        void push(const TYPE& a);
        TYPE pop();
        TYPE peek() const;
};

#endif