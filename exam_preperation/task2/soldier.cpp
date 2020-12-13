#include <iostream>
#include <cstring>

#include "soldier.hpp"

Soldier::Soldier(const char *_name, unsigned short _ages, int _skills, int _wage) 
{
        strncpy(name, _name, strlen(_name));
        ages = _ages;
        skills = _skills;
        wage = _wage;        
}

void Soldier::print() 
{
        std::cout << name << ", " << ages << ", " << skills << ", " << wage << std::endl;         
}
