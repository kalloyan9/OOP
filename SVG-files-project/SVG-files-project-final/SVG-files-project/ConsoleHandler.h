#pragma once
#include "ShapeContainer.h"
#include "Globals.hpp"


class ConsoleHandler
{
public:
	ConsoleHandler();//default constructor

public:
	//methods
	void start();

	bool openFile(const string& _fileName);// + deserialize
	void closeFile();
	
	void setFileName(const string& _fileName);
	inline string getFileName()const { return fileName; }	
	bool saveFile(const string& _fileName);
	//bool saveFileAs(const string& _newFileName);//serialize in _newFileName

private:
	//helper
	void helperSave(const string& _fileName);

	//data
	//std::ifstream in;
	//std::ofstream out;
	string fileName;
	bool isFileOpen;
	ShapeContainer shapes;
};
