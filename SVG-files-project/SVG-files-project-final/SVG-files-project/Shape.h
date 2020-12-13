#pragma once
#include <fstream>
#include "Globals.hpp"
class Shape //this is a base class for all shapes
{
public:
	virtual void printInfo()const = 0;//virtual because derived classes will have it, 
									//pure virtual because this class is abstracts
	virtual Shape* clone() = 0;//pue virtual function for the polymorphism
        virtual ~Shape() = 0;

	virtual void writeInfo(std::ofstream& out)const = 0;//serialize

	virtual void setColor(const string& _color) = 0;
	virtual string getColor()const = 0;
protected:
	string color; //color and transperancy
};
//circle is a shape
//rectangle is a shape
//triangle is a shape
//inheratance + polymorphism