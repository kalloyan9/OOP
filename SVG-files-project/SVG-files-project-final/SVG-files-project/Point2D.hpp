#pragma once
#include <fstream>
#include <iostream>


struct Point2D
{
	double x;
	double y;

	//operators overloading
	friend std::istream& operator>>(std::istream& in, Point2D& point);//chupi za line, zatova tam pravq novo
	friend std::ostream& operator<<(std::ostream& out, const Point2D& point);
	Point2D(double _x = 0, double _y = 0) : x(_x), y(_y) {	}
};


inline std::istream& operator>>(std::istream& in, Point2D& point)//ok
{
	in >> point.x >> point.y;
	return in;
}


inline std::ostream& operator << (std::ostream& out, const Point2D& point)//ok
{
	out << point.x << " " << point.y;
	return out;
}
