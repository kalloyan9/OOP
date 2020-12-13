#include <iostream>


#include "Globals.hpp"
#include "ConsoleHandler.h"
#include "Point2D.hpp"
#include "Circle.h"
#include "Rectangle.h"
#include "Line.h"


ConsoleHandler::ConsoleHandler()
	: isFileOpen(false),
	shapes()
	//, fileName(GLOBALS::DEFAULT_FILE_NAME)
{	}


void ConsoleHandler::setFileName(const string& _fileName)
{
	fileName = _fileName;
}


void ConsoleHandler::helperSave(const string& _fileName)
{
	std::ofstream _out(_fileName);//opening new file + erasing it content
	if (!_out)//checking error
	{
		std::cerr << "error opening file.\n";//or thorw exception
		return;
	}
	
	_out << GLOBALS::FIRST_LINE << std::endl << GLOBALS::SECOND_LINE << std::endl;
	_out << shapes;//serialize
	_out << GLOBALS::DEFAULT_LAST_LINE << std::endl;//new - ok
	_out.close();
}


bool ConsoleHandler::saveFile(const string& _fileName)// + serialize
{
	helperSave(_fileName);//using the same stream
	return true;
}


//bool ConsoleHandler::saveFileAs(const string& _newFileName)// + serialize
//{
//	helperSave(_newFileName);
//	return true;
//}


//opening a file and extracting the supported info
bool ConsoleHandler::openFile(const string& _fileName)// + deserialize
{
	std::ifstream in(_fileName);
	if (!in)
	{
		std::cerr << "error opening file.\n";
		return false;
	}
	isFileOpen = true;
	//first two lines
	in.getline(GLOBALS::FIRST_LINE, GLOBALS::MAX_STR_INPUT);
	in.getline(GLOBALS::SECOND_LINE, GLOBALS::MAX_STR_INPUT);
	//
	in >> shapes;//deserialize
	in.close();
	//ne mojah da izmislq po hubav nachin za izvlichane na informaciqta navednuj
	in.open(_fileName);
	shapes.getColors(in, shapes);
	in.close();
	//
	return true;
}


void ConsoleHandler::closeFile()
{
//	in.close();
//	out.close();
	isFileOpen = false;
}
//

void ConsoleHandler::start()
{
	bool endFunc = false;
	do
	{
		//interface
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		if (isFileOpen)
			std::cout << "file opened (\"" << fileName << "\")\n";
		std::cout << "********************************************\n";
		std::cout << "* Please type command\n";
		std::cout << "* exit - to exit\n";
		std::cout << "* open <file name> - to open file\n";
		std::cout << "* close - to close opened file\n";
		std::cout << "* save - to save opened file\n";
		std::cout << "* saveAs <file name> - to save opened file as\n";
		std::cout << "* help - for help\n";

		if (isFileOpen)
		{
			std::cout << "* print - to print all shapes\n";
			std::cout << "* create - to create a new shape*\n";
			std::cout << "* erase <n> - to erase on idx <n>\n";
			std::cout << "*(NOT SUPPORTED) translate <n> - translate shape on idx<n>\n";
			std::cout << "*(NOT SUPPORTED) withing option <n> - printing in region\n";
			//TODO:
			//translate n
			//withing option Извежда на екрана всички фигури, 
			//които изцяло се съдържат в даден регион. 
			//Потребителят може да укаже чрез <option> 
			//какъв да бъде регионът – кръг (circle) или правоъгълник (rectangle)
		}
		std::cout << "********************************************\n";

		//command handler from the console
		char cmd[GLOBALS::MAX_STR_INPUT];
		do
		{
			std::cout << "$ ";
			std::cin.getline(cmd, GLOBALS::MAX_STR_INPUT);
		}
		while (strlen(cmd)<2);
		char* _cmd = strtok(cmd, " ");
		int command = GLOBALS::returnCommand(_cmd);//converting the string command to a number

		if (isFileOpen)
		{
			//catching cases
			switch (command)
			{
			case 0://exit - done
				closeFile();
				std::cout << "- - - - -Good bye.\n";
				endFunc = true;
				return;
			case 1://open - done
				std::cout << "Already opened a file, you may want to close it.\n";
				break;
			case 2://close - done
				closeFile();
				std::cout << "- -file closed.\n";
				shapes.nullSize();//fast cleaning from RAM without deleting and shrinking
				break;
			case 3://save - done
				if (saveFile(fileName))
				{
					std::cout << "- -saved.\n";
					closeFile();
					std::cout << "- -file closed.\n";
					shapes.nullSize();//fast cleaning from RAM without deleting and shrinking
				}
				else std::cerr << "couldnt save file.\n";
				break;
			case 4://save as - done
			{
				char* newFileName = strtok(NULL, " ");
				if (!newFileName)
				{
					std::cerr << "please input file";
					break;
				}
				saveFile(newFileName);//saveAs
				std::cout << "- -saved.\n";
				break;
			}
			case 5://help
				//TODO
				std::cout << "soon.\n";
				break;
			case 6://print - done
				shapes.printInfo();
				break;
			case 7://create - done
				std::cout << "input figure name:\n(line, rect and circle supported)\n";
				char input[GLOBALS::MAX_STR_INPUT];
				std::cin.getline(input, GLOBALS::MAX_STR_INPUT);
				if (strcmp(input, &GLOBALS::CIRCLE[0]) == 0)
				{
					Point2D center;
					std::cout << "input center coords: ";
					std::cin >> center;
					std::cout << "input radius: ";
					double radius;
					std::cin >> radius;
					std::cin.ignore(GLOBALS::MAX_STR_INPUT, '\n');
					//stroke = "blue" fill = "transparent" stroke - width = "5";
					string stroke, fill, stroke_width;
					//vs e na doverie na potrebitelq
					std::cout << "input stroke: ";
					std::cin >> stroke;
					std::cout << "input fill: ";
					std::cin >> fill;
					std::cout << "input stroke-width: ";
					std::cin >> stroke_width;
					std::cin.ignore(GLOBALS::MAX_STR_INPUT, '\n');
					string _color = "stroke=\"" + stroke + "\""
						+ " fill=\"" + fill + "\""
						+ " stroke-width=\"" + stroke_width + "\"\/>";
					//
					shapes.add(new Circle(center, radius, _color));//constructing Circle* with the constructor
				}
				else if (strcmp(input, &GLOBALS::RECTANGLE[0]) == 0)
				{
					Point2D a;
					std::cout << "Input two cords: ";
					std::cin >> a;
					std::cout << "input width and height: ";
					double width, height;
					std::cin >> width >> height;
					std::cin.ignore(GLOBALS::MAX_STR_INPUT, '\n');
					//stroke = "blue" fill = "transparent" stroke - width = "5";
					string stroke, fill, stroke_width;
					//vs e na doverie na potrebitelq
					std::cout << "input stroke: ";
					std::cin >> stroke;
					std::cout << "input fill: ";
					std::cin >> fill;
					std::cout << "input stroke-width: ";
					std::cin >> stroke_width;
					std::cin.ignore(GLOBALS::MAX_STR_INPUT, '\n');
					string _color = "stroke=\"" + stroke + "\""
						+ " fill=\"" + fill + "\""
						+ " stroke-width=\"" + stroke_width + "\"\/>";
					//
					shapes.add(new Rectangle(a, width, height, _color));//constructing Rectangle* with the constructor
				}
				else if (strcmp(input, &GLOBALS::LINE[0]) == 0)
				{
					double x1, x2;
					std::cout << "input two x1 and x2 coords: ";
					std::cin >> x1 >> x2;
					double y1, y2;
					std::cout << "input two y1 and y2 coords: ";
					std::cin >> y1 >> y2;
					Point2D p1(x1, y1);
					Point2D p2(x2, y2);
					std::cin.ignore(GLOBALS::MAX_STR_INPUT, '\n');
					//stroke = "blue" stroke - width = "5";
					string stroke, fill, stroke_width;
					//vs e na doverie na potrebitelq
					std::cout << "input stroke: ";
					std::cin >> stroke;
					std::cout << "input stroke-width: ";
					std::cin >> stroke_width;
					std::cin.ignore(GLOBALS::MAX_STR_INPUT, '\n');
					string _color = "stroke=\"" + stroke + "\""
						+ " stroke-width=\"" + stroke_width + "\"\/>";
					//
					shapes.add(new Line(p1, p2, _color));//constructing Line* with the constructor
				}
				else
					std::cerr << "unsuported figure.\n";
				break;
			case 8://remove - done
			{
				char* idx = strtok(NULL, " ");
				if (!idx)
				{
					std::cerr << "please input index.\n";
					break;
				}
				int index = atoi(idx);
				if (shapes.erase(index))
					std::cout << "- -erased<" << index << ">\n";
				else
					std::cerr << "no such index.\n";
				break;
			}
			case 9://TODO
				std::cout << "soon.\n";
				break;
			case 10://TODO
				std::cout << "soon.\n";
				break;
			default://done
				std::cerr << "invalid command.\n";
				break;
			}
		}
		else //no opened file
		{
			switch (command)
			{
			case 0://exit - done
				std::cout << "- - - - -Good bye.\n";
				endFunc = true;
				return;
			case 1://open - done
			{
				char* _fileName = strtok(NULL, " ");
				if (!_fileName)
				{
					std::cerr << "Please input file name: ";
					break;
				}
				setFileName(_fileName);
				openFile(fileName);
				break;
			}
			case 2://close - done
				std::cout << "no file opened.\n";
				break;
			case 3://save - done
				std::cerr << "No opened file :(\n";
				break;
			case 4://save as - done
				std::cerr << "No opened file :(\n";
				break;
			case 5://help - done
				std::cout << "THIS IS HELP MENU!\n";
				//TODO
				std::cout << "soon.\n";
				break;
			default://invalid command - done
				std::cerr << "Invalid command.\n";
				break;
			}
		}
	} while (!endFunc);
}