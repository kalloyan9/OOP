#pragma once
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;

#include "Syntax.h"
#include "User.h"
#include "Publication.h"
using namespace globals;

namespace globals
{
	static bool endProgram = false;
	static const int MAX_INPUT_SIZE = 128;
}

class ConsoleHandler
{
public:
	void run();
	unsigned countUsers();
	int findUsername(const string& name);

private:
	string command;
	Syntax syntax;
	vector<User> users;
	vector<Publication> publications;
};

