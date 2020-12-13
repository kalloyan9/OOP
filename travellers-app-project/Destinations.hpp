#pragma once
#include "Static_Namespace.hpp"
#include "Users.hpp"

using namespace static_namespace;
struct Destinations
{
    //methods
    void setName(const char* destName);
    void addInfo(const Users& users);
    void getInfo();

    //data
    char name[MAX_STR_INPUT];
    int avg;
};
