#pragma once

class Vector_String
{
public:
    // Big four
    Vector_String();
    Vector_String(const Vector_String& other);
    Vector_String& operator=(const Vector_String& other);
    ~Vector_String();

public:
    // Methods
    int size()const;
    int capacity()const;
    char* at(int index)const;
    void push_back(const char* element);
    void erase(int index);
    void reserve(int capacity);

private:
    // Helper methods used in the big four
    void copy(const Vector_String& other);
    void clear();

private:
    // Data members should always be private
    int m_size;
    int m_capacity;
    char** m_arr;
};