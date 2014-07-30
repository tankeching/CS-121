#ifndef __Shapes__Triangle__
#define __Shapes__Triangle__

#include <iostream>
#include <string>
using namespace std;

#include "Shape.h"

class Triangle: public Shape {
public:
	Triangle();
	Triangle(double sideA, double sideB, double sideC);

	double sideA() const;
	double sideB() const;
	double sideC() const;

	void sideA(double sideA);
	void sideB(double sideB);
	void sideC(double sideC);

	virtual double perimeter() const;
	virtual double area() const;
	virtual double length() const;
	virtual double width() const;
	virtual string name() const;

private:
	double max(double m, double n) const;
	double heron() const;

	bool valid() const;

private:
	double _sideA;
	double _sideB;
	double _sideC;
};

#endif