#pragma once

#include <iostream>
#include <cstring>
#include <cstdlib>


#include "Globals.hpp"
#include "Point2D.hpp"
#include "ShapeContainer.h"
#include "Line.h"
#include "Circle.h"
#include "Rectangle.h"

using std::string;


ShapeContainer::ShapeContainer(size_t capacity) : f_capacity(capacity), f_size(0)
{
	f_shapes = new Shape * [capacity];
}


ShapeContainer::ShapeContainer(const ShapeContainer& other)
{
	copy(other);
}


ShapeContainer& ShapeContainer::operator=(const ShapeContainer& other)
{
	if (this != &other)
	{
		clean();
		copy(other);
	}
	return *this;
}


ShapeContainer::~ShapeContainer()
{
	clean();
}


size_t ShapeContainer::size() const
{
	return f_size;
}


void ShapeContainer::printInfo() const
{
	for (size_t i = 0; i < this->size(); i++)
		f_shapes[i]->printInfo();
}


void ShapeContainer::add(Shape* newShape)
{
	if (f_size >= f_capacity)
	{
		resize(f_capacity * 2);
	}

	f_shapes[f_size] = newShape;
	++f_size;
}


Shape* ShapeContainer::at(size_t i) const
{
	if (i < f_size)
	{
		return f_shapes[i];
	}
	else return nullptr;
}


void ShapeContainer::nullSize()
{
	f_size = 0;
}


bool ShapeContainer::erase(size_t index)//fast eresing
{
	if (index < f_size)
	{
		for (size_t i = index; i < f_size - 1; ++i)//shifting left
		{
			f_shapes[i] = f_shapes[i + 1];
		}
		--f_size;
		return true;
	}
	else return false;
}


void ShapeContainer::copy(const ShapeContainer& other)
{
	f_size = other.f_size;
	f_capacity = other.f_capacity;
	f_shapes = new Shape * [f_capacity];

	for (size_t i = 0; i < f_size; i++)
	{
		f_shapes[i] = other.f_shapes[i]->clone();
	}
}


void ShapeContainer::clean()
{
	for (size_t i = 0; i < f_size; i++)
	{
		delete f_shapes[i];
	}

	delete[] f_shapes;
}


void ShapeContainer::resize(size_t newCapacity)
{
	if (newCapacity < f_capacity)
	{
		return;
	}

	f_capacity = newCapacity;
	Shape** newShapes = new Shape * [f_capacity];

	for (size_t i = 0; i < f_size; i++)
	{
		newShapes[i] = f_shapes[i];
	}

	delete[] f_shapes;
	f_shapes = newShapes;
}


inline bool isWord(char t)
{
	return (t >= 'a' && t <= 'z') || (t >= 'A' && t <= 'B');
}


inline bool isNum(char t)
{
	return (t >= '0' && t <= '9') || t == '.'; // '.' for double
}


std::ifstream& operator>>(std::ifstream& in, ShapeContainer& container)//deserialize
{
	const int MAX_STR = GLOBALS::MAX_STR_INPUT * 2;
	char read[MAX_STR];
	read[0] = '\0';
	char copyRead[MAX_STR*10];
	int c;
	while (in >> read)
	{
		bool foundCircle = false;
		bool foundRectangle = false;
		bool foundLine = false;

		//read + 1 - ignoring the '>'
		if (!strcmp(read + 1, &GLOBALS::CIRCLE[0]))//found circle
			foundCircle = true;
		else if (!strcmp(read + 1, &GLOBALS::RECTANGLE[0]))//found rectangle
			foundRectangle = true;
		else if (!strcmp(read + 1, &GLOBALS::LINE[0]))//found Line
			foundLine = true;

		if ((foundCircle ^ foundRectangle) ^ foundLine)
		{
			const char* p_read = read;
			c = 0;
			while (*p_read)//getting the word in buffer copyRead
			{
				copyRead[c] = *p_read;
				++c;
				++p_read;
			}
			copyRead[c] = ' ';
			++c;
			while (in >> read)
			{
				bool _break = false;
				p_read = read;
				while (*p_read)//getting the word in buffer copyRead
				{
					copyRead[c] = *p_read;
					++c;
					++p_read;
					if (*p_read == '>')
						_break = true;
					if (_break)
						break;
				}
				if (_break)
					break;
			}
			copyRead[c++] = '>';
			copyRead[c] = '\0';
			//all supported figure got in copyRead;
			//std::cout << copyRead << std::endl << std::endl;

			//TODO extracting the numbers from copyRead for constructor
			//new
			int n = 0;
			char cNum[GLOBALS::MAX_STR_INPUT];
			bool haveNumber = false;

			if ((foundCircle ^ foundRectangle) ^ foundLine)
			{
				const int MAX_COORDS = 20;
				char nums[MAX_COORDS][GLOBALS::MAX_STR_INPUT];
				p_read = copyRead;
				n = 0;
				while (*p_read)//getting numbers in cNum
				{
					//std::cout << *p_read << " ";
					while (*p_read && !isNum(*p_read))//skipping non numbers
					{
						++p_read;
						haveNumber = false;
					}
					c = 0;
					while (*p_read && isNum(*p_read))//getting number
					{
						haveNumber = true;
						cNum[c] = *p_read;
						++c;
						++p_read;
					}
					cNum[c] = '\0';
					//std::cout << n << ": " << cNum << std::endl;
					if (haveNumber)
					{
						strcpy(nums[n], cNum);//getting nums in array
						//std::cout << nums << std::endl;
						++n;
						++p_read;
					}
				}
				if (foundCircle)
				{
					Point2D center(atof(nums[0]), atof(nums[1]));
					container.add(new Circle(center, atof(nums[2])));
				}
				else if (foundRectangle)
				{
					Point2D a(atof(nums[0]), atof(nums[1]));
					double width = atof(nums[2]);
					double height = atof(nums[3]);
					container.add(new Rectangle(a, width, height));
				}
				else if (foundLine)
				{
					//these are the correct indexes because it's reading x1 y1 x2 y2 like numbers
					Point2D first(atof(nums[1]), atof(nums[5]));
					Point2D second(atof(nums[3]), atof(nums[7]));
					container.add(new Line(first, second));
				}
			}
			// working fine for integers, to test for double
			// working fine with doubles too
			// done
		}
	}
	return in;
} //working


//new
void ShapeContainer::getColors (std::ifstream& in, ShapeContainer& container)//deserializing color and transperancy
{
	char read[GLOBALS::MAX_STR_INPUT];
	bool foundCircle, foundRectangle, foundLine;
	int index = 0;
	
	while (!in.eof())
	{
		in >> read;
		foundCircle = false;
		foundRectangle = false;
		foundLine = false;
	
		if (!strcmp(read+1, &GLOBALS::CIRCLE[0]))//read + 1 ignors '<'
		{
			foundCircle = true;
		}
		else if (!strcmp(read + 1, &GLOBALS::RECTANGLE[0]))//read + 1 ignors '<'
		{
			foundRectangle = true;
		}
		else if (!strcmp(read + 1, &GLOBALS::LINE[0]))//read + 1 ignors '<'
		{
			foundLine = true;
		}

		int k = 0; //kratnost
		if (foundCircle || foundRectangle || foundLine)
		{
			while (read[strlen(read) - 1] != '>')
			{
				in >> read;
				++k;
				if (foundRectangle && k == 5)
				{
					char colorRect[GLOBALS::MAX_STR_INPUT];
					strcpy(colorRect, read);
					strcat(colorRect, " ");
					while (read[strlen(read) - 1] != '>')
					{
						in >> read;
						if (strlen(read) - 1 == '>')
							break;
						strcat(colorRect, read);
						strcat(colorRect, " ");
					}
					this->at(index)->setColor(colorRect);
					//std::cout << this->at(index)->getColor();
				}
				else if (foundCircle && k == 4)
				{
					char colorCircle[GLOBALS::MAX_STR_INPUT];
					strcpy(colorCircle, read);
					strcat(colorCircle, " ");
					while (read[strlen(read) - 1] != '>')
					{
						in >> read;
						if (strlen(read) - 1 == '>')
							break;
						strcat(colorCircle, read);
						strcat(colorCircle, " ");
					}
					this->at(index)->setColor(colorCircle);
					//std::cout << this->at(index)->getColor();
				}
				else if (foundLine && k == 5)
				{
					char colorLine[GLOBALS::MAX_STR_INPUT];
					strcpy(colorLine, read);
					strcat(colorLine, " ");
					while (read[strlen(read) - 1] != '>')
					{
						in >> read;
						if (strlen(read) - 1 == '>')
							break;
						strcat(colorLine, read);
						strcat(colorLine, " ");
					}
					this->at(index)->setColor(colorLine);
					//std::cout << this->at(index)->getColor();
				}
					
			}
			++index;
		}
		//std::cout << std::endl;
		if (in.eof())
			break;
	}
}


std::ofstream& operator<<(std::ofstream& out, const ShapeContainer& container)
{
	for (size_t i = 0; i < container.size(); i++)
	{
		const Shape* gotShape = container.at(i);
		gotShape->writeInfo(out);
		out << std::endl;
	}
	return out;
}
