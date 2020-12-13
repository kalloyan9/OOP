#pragma once
#include "Users.hpp"
#include "Globals.hpp"
#include "Destinations.hpp"

class Menu
{
public:
	Menu():endProgram(false){ }
	void menu1(Users&);
	void menu2(Users&, Destinations&);
	bool endProgram;
};

