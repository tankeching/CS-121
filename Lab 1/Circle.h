#ifndef __Circle__Circle__
#define __Circle__Circle__

#include <iostream>
using namespace std;

class Circle{
public:
	Circle();
	Circle(double radius);
	void radius(double value);
	double radius() const;
	double area() const;
	double perimeter() const;

private:
	double _radius;
};

#endif