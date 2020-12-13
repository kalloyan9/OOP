#pragma once
#include <iostream>


#include "Line.h"
#include "MathFormulas.hpp"
#include "Globals.hpp"


Line::Line(Point2D _a, Point2D _b, const string& _color) : a(_a), b(_b) 
{
	setColor(_color);
}


Line::Line(Point2D _a, Point2D _b) : a(_a), b(_b)	{	}


void Line::printInfo() const
{
	std::cout << GLOBALS::LINE << " ";
	std::cout << a.x << " " << b.x << " " << a.y << " " << b.y << " " << std::endl;
}


void Line::writeInfo(std::ofstream& out) const
{
	if (out.is_open())
	{
		out << "<" << GLOBALS::LINE << " x1=\"" << a.x << "\" x2=\"" << b.x << "\" y1=\""
			<< a.y << "\" y2=\"" << b.y << "\" " << color;
	}
}


Shape* Line::clone()
{
	return new Line(*this);
}

Line::~Line() 
{
        delete this;
}


void Line::setColor(const string& _color)
{
	color = _color;
}


string Line::getColor()const
{
	return color;
}