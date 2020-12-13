/*
    Project #1 - Traveller's app
    written by Kaloyan Mehandzhiyski
    fn 45673
*/


//my very first and awful projects without real console handler and bad architecture
//and withoud good OOP practics
//because I started it very early
#include <iostream>

#include "Users.hpp"
#include "Globals.hpp"
#include "Destinations.hpp"
#include "Menu.hpp"

int main()
{
    Users user;
    Destinations destination;
    Menu menu;

    menu.menu1(user);
    
    if(!menu.endProgram)
        menu.menu2(user, destination);

    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << std::endl << "---------------------" << "Good Bye!" << std::endl;
    return 0;
}