#ifndef __Shapes__Rectangle__
#define __Shapes__Rectangle__

#include <iostream>
using namespace std;

#include "Shape.h"

class Rectangle : public Shape{
public:
	Rectangle();
	Rectangle(double length, double width);

	void width(double width);
	void length(double length);

	virtual double area() const;
	virtual double perimeter() const;
	virtual double length() const;
	virtual double width() const;
	virtual string name() const;

private:
	double _width, _length;
};

#endif