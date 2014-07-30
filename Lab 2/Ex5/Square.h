#ifndef __Shapes__Square__
#define __Shapes__Square__

#include <iostream>
#include <string>
using namespace std;

#include "Rectangle.h"

class Square : public Rectangle{
public:
	Square();
	Square(double side);

	double side() const;
	void side(double side);

	string name() const;

private:
	double _side;
};

#endif