#include <iostream>

#include "soldier.hpp"

int main() 
{
        Soldier a("ivac", 12u, 2, 100);
        a.print();
        Soldier b;
        b = a;
        b.print();
        Soldier c(b);
        c.print();

        return 0;
}