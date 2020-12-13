#pragma once
#include<iostream>
#include<cstring>
#include<fstream>

#include "Users.hpp"
#include "Static_Namespace.hpp"
#include "cstring"
using namespace static_namespace;

namespace globals
{
    inline void cin(char* str)
    {
        std::cin >> str;
        std::cin.ignore(MAX_STR_INPUT, '\n');
    }


    class simpleInterface
    {
    public:
        void printLogReg();
        void printLookAdd();
    };

    class functionality
    {
    public:
        int logRegFunc(Users& user);
        int lookAddFunc(Users& user);
    };
}