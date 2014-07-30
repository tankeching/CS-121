#include "Ellipse.h"
#include <cmath>

const double pi = 3.1415926589;

Ellipse::Ellipse() : Ellipse(0, 0){}
Ellipse::Ellipse(double radius) : Ellipse(radius, radius){}
Ellipse::Ellipse(double semimajor, double semiminor) : _semimajor(semimajor), _semiminor(semimajor){}

double Ellipse::semimajor() const { return _semimajor; }
void Ellipse::semimajor(double semimajor) { _semimajor = semimajor; }

double Ellipse::semiminor() const { return _semiminor; }
void Ellipse::semiminor(double semiminor) { _semiminor = semiminor; }

double Ellipse::area() const { return pi * _semimajor * _semiminor; }
double Ellipse::perimeter() const {
	double a = _semimajor;
	double b = _semiminor;
	return pi * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));
}

double Ellipse::length() const { return 2 * _semimajor; }
double Ellipse::width() const { return 2 * _semiminor; }
string Ellipse::name() const { return "Ellipse"; }

double Ellipse::eccentricity() const { return focus() / _semimajor; }
double Ellipse::focus() const{
	return sqrt(pow(_semimajor, 2) - pow(_semiminor, 2));
}

