#pragma once
#include "Shape.h"
#include "Point2D.hpp"

class Line : public Shape //Line is a Shape
{
public:
	Line(Point2D _a, Point2D _b, const string& _color);//constructor with default values of points (0,0) for each
	Line(Point2D _a, Point2D _b);
	virtual Shape* clone() override;
        virtual ~Line();

public:
	//methods
	virtual void printInfo() const override;//override is default but its for readability
	virtual void writeInfo(std::ofstream& out) const override;//serialize
	virtual void setColor(const string& _color) override;
	virtual string getColor()const override;

private:
	//data
	Point2D a;
	Point2D b;
};
