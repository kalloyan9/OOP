#pragma once
#include "Shape.h"
#include "Point2D.hpp"

class Circle : public Shape//circle is a shape
{
public:
	Circle(Point2D c, double r, const string& _color);//parameterized constructor
	Circle(Point2D c, double r);//parameterized constructor only with points
	virtual Shape* clone() override;
        virtual ~Circle();

public:
	//methods
	virtual void printInfo() const override;//override is default but its for readability
	virtual void writeInfo(std::ofstream& out) const override;//serialize in file
	virtual void setColor(const string& _color) override;
	virtual string getColor()const override;

private:
	//data
	Point2D center;
	double radius;
};