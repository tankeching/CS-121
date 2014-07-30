#ifndef __Rectangles__Rectangles__
#define __Rectangles__Rectangles__

#include <iostream>
using namespace std;

class Rectangle{
public:
	Rectangle();
	Rectangle(double length, double width);

	void length(double length);
	void width(double width);

	double area() const;


private:
	double _length, _width;
};

#endif