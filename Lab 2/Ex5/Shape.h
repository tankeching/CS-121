#ifndef __Shapes__Shape__
#define __Shapes__Shape__

#include <iostream>
#include <string>
using namespace std;

class Shape{
public:
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
	virtual double length() const = 0;
	virtual double width() const = 0;
	virtual string name() const = 0;

};

#endif