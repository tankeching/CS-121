#ifndef __Shapes__Circle__
#define __Shapes__Circle__

#include <iostream>
using namespace std;

#include "Ellipse.h"

class Circle : public Ellipse{
public:
	Circle();
	Circle(double radius);

	void radius(double value);
	double radius() const;

	double diameter() const;
	double circumferece() const;

	string name() const;

private:

	double _radius;

};

#endif