#pragma once
#include <fstream>
#include "Shape.h"

static const size_t DEFAULT_CAPACITY = 16;

class ShapeContainer
{
public:
	//big four
	ShapeContainer(size_t capacity = DEFAULT_CAPACITY);
	ShapeContainer(const ShapeContainer& other);
	ShapeContainer& operator=(const ShapeContainer& other);
	~ShapeContainer();

public:
	//methods
	size_t size()const;
	void printInfo() const;
	void add(Shape* newShape);
	Shape* at(size_t i) const;
	void nullSize();
	bool erase(size_t index);//new - ok

	void getColors(std::ifstream& in, ShapeContainer& container);

	//overwritted operators
	friend std::ifstream& operator>>(std::ifstream& in, ShapeContainer& container);
	friend std::ofstream& operator<<(std::ofstream& out, const ShapeContainer& container);
private:
	//helpers
	void copy(const ShapeContainer& other);
	void clean();
	void resize(size_t newCapacity);

private:
	//all data must be private
	Shape** f_shapes;
	size_t f_size;
	size_t f_capacity;
};