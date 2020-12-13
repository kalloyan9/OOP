#pragma once
#include <cstring>
#include <string>
using std::string;

namespace GLOBALS
{
	//global constants
	static const int MAX_STR_INPUT = 100;
	static const string DEFAULT_FILE_NAME = "shapes.txt";
	static const string LINE = "line";
	static const string RECTANGLE = "rect";
	static const string CIRCLE = "circle";

	//precomputing
	static const string DEFAULT_FIRST_LINE = "<?xml version=\"1.0\" standalone=\"no\"?>\n<svg width=\"200\" height=\"250\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">";     
	static char FIRST_LINE[MAX_STR_INPUT];
	static char SECOND_LINE[MAX_STR_INPUT];
	static const string DEFAULT_LAST_LINE = "</svg>";
	static const string DEFAULT_COLOR_N_STROKE = "stroke=\"black\" fill=\"transparent\" stroke-width=\"5\"";
	
	inline int returnCommand(const string& command)//converting string to a number
	{
		if (command == "exit")
			return 0;
		else if (command == "open")
			return 1;
		else if (command == "close")
			return 2;
		else if (command == "save")
			return 3;
		else if (command == "saveAs")
			return 4;
		else if (command == "help")
			return 5;
		else if (command == "print")
			return 6;
		else if (command == "create")
			return 7;
		else if (command == "erase")
			return 8;
		else if (command == "translate")
			return 9;
		else if (command == "withing option")
			return 10;
		else return -1;//invalid
	}
}