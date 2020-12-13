#pragma once
#include "Shape.h"
#include "Point2D.hpp"

class Rectangle : public Shape
{
public:
	Rectangle(Point2D _a, double _width, double _height, const string& _color);//parameterized constructor
	Rectangle(Point2D _a, double _width, double _height);
	virtual Shape* clone() override;
        virtual ~Rectangle();

public:
	//methods
	virtual void printInfo() const override;//override is default but its for readability
	virtual void writeInfo(std::ofstream& out) const override;//serialize in file
	virtual void setColor(const string& _color) override;
	virtual string getColor()const override;

private:
	//data
	Point2D a;
	double width;
	double height;
};