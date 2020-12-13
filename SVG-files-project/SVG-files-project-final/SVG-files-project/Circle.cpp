//for PI const
#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>


#include "Circle.h"
#include "Globals.hpp"


Circle::Circle(Point2D c, double r, const string& _color) : center(c), radius(r) 
{
	setColor(_color);
}


Circle::Circle(Point2D c, double r) : center(c), radius(r)	{	}


void Circle::printInfo() const
{
	std::cout << GLOBALS::CIRCLE << " ";
	std::cout << center << " " << radius << " " << std::endl;
}


void Circle::writeInfo(std::ofstream& out) const
{
	if (out.is_open())
	{
		out << "<" << GLOBALS::CIRCLE << " cx=\"" << center.x << "\" cy=\"" << center.y
			<< "\" r=\"" << radius << "\" " << color;
	}
}


Shape* Circle::clone()
{
	return new Circle(*this);
}

Circle::~Circle() 
{
        delete this;
}


void Circle::setColor(const string& _color)
{
	color = _color;
}


string Circle::getColor()const
{
	return color;
}