#include <cstring>
#include <cassert>

#include "Vector_String.hpp"
#include "Static_Namespace.hpp"

const int DEFAULT_CAPACITY = 8;
const int MAX_LEN = static_namespace::MAX_STR_INPUT;

Vector_String::Vector_String()
{
    m_size = 0;
    m_capacity = DEFAULT_CAPACITY;
    m_arr = new char* [m_capacity];
    for (int i = 0; i < m_size; ++i)
        m_arr[i] = new char[MAX_LEN];
}


Vector_String::Vector_String(const Vector_String& other)
{
    copy(other);
}


Vector_String& Vector_String::operator=(const Vector_String& other)
{
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}


Vector_String::~Vector_String()
{
    clear();
}


void Vector_String::copy(const Vector_String& other)
{
    this->m_size = other.m_size;
    this->m_capacity = other.m_capacity;
    this->m_arr = new char* [other.m_capacity];
    for (int i = 0; i < other.m_size; i++)
    {
        this->m_arr[i] = new char[MAX_LEN];
        strcpy(this->m_arr[i], other.m_arr[i]);
    }
}


void Vector_String::clear()
{
    for (int i = 0; i < m_size; ++i)
    {
        delete m_arr[i];
    }
    delete[] m_arr;
    m_arr = nullptr;
}


int Vector_String::size()const
{
    return m_size;
}


int Vector_String::capacity()const
{
    return m_capacity;
}


char* Vector_String::at(int index)const
{
    assert(index <= m_size);
    return m_arr[index];
}


void Vector_String::push_back(const char* element)
{
    if (m_size >= m_capacity)
        reserve(2 * m_capacity);

    m_arr[m_size] = new char[MAX_LEN]; ///!!!
    strcpy(m_arr[m_size], element);
    ++m_size;
}


void Vector_String::erase(int index)
{
    for (int i = index; i < m_size - 1; i++)
    {
        strcpy(m_arr[i], m_arr[i + 1]);
    }
    m_size--;
}


void Vector_String::reserve(int capacity)
{
    //    std::cerr<<" start resizing\n";
    if (capacity > m_capacity) {
        char** new_arr = new char* [capacity];
        for (int i = 0; i < m_size; i++)
        {
            new_arr[i] = new char[MAX_LEN];
            strcpy(new_arr[i], m_arr[i]);
        }

        for (int i = 0; i < m_capacity; ++i)
            delete[] m_arr[i];
        delete[] m_arr;
        m_capacity = capacity;
        m_arr = new_arr;
    }
}