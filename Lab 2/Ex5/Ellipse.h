#ifndef __Shapes__Ellipse__
#define __Shapes__Ellipse__

#include <iostream>
#include <string>
using namespace std;

#include "Shape.h"

class Ellipse : public Shape{
public:
	Ellipse();
	Ellipse(double radius);
	Ellipse(double semimajor, double semiminor);

	void semimajor(double semimajor);
	double semimajor() const;

	void semiminor(double semiminor);
	double semiminor() const;

	virtual double area() const;
	virtual double perimeter() const;
	virtual double length() const;
	virtual double width() const;
	virtual string name() const;

	double eccentricity() const;
	double focus() const;

private:
	double _semimajor, _semiminor;
};

#endif