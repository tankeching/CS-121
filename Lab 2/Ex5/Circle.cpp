#include "Circle.h"

#include <iostream>
#include <cmath>
using namespace std;

const double pi = 3.141592653;

Circle::Circle() : Circle(0){}
Circle::Circle(double radius) : Ellipse(radius, radius){}

double Circle::radius() const { return _radius; }

void Circle::radius(double radius){
	_radius = radius;
	semimajor(radius);
	semiminor(radius);
}

double Circle::diameter() const{ return _radius * 2; }
double Circle::circumferece() const{ return _radius * 2 * pi; }

string Circle::name() const { return "Circle"; }