#include "Rectangle.h"
#include "MathFormulas.hpp"
#include "Globals.hpp"


Rectangle::Rectangle(Point2D _a, double _width, double _height, const string& _color) : a(_a), width(_width), height(_height) 
{
	setColor(_color);
}


Rectangle::Rectangle(Point2D _a, double _width, double _height) : a(_a), width(_width), height(_height)	{	}


void Rectangle::printInfo() const
{
	std::cout << GLOBALS::RECTANGLE << " ";
	std::cout << a << " " << width << " " << height << " " << std::endl;
}


void Rectangle::writeInfo(std::ofstream& out) const
{
	if (out.is_open())
	{
		out << "<" << GLOBALS::RECTANGLE << " x=\"" << a.x << "\" y=\"" << a.y
			<< "\" width=\"" << width << "\" height=\"" << height << "\" " << color;
	}
}


Shape* Rectangle::clone()
{
	return new Rectangle(*this);
}

Rectangle::~Rectangle() 
{
        delete this;
}


void Rectangle::setColor(const string& _color)
{
	color = _color;
}


string Rectangle::getColor()const
{
	return color;
}