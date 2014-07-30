#include "Rectangle.h"

Rectangle::Rectangle() : _width(0), _length(0){}
Rectangle::Rectangle(double length, double width) : _width(width), _length(length){}

void Rectangle::width(double width) { _width = width; }
void Rectangle::length(double length) { _length = length; }

double Rectangle::area() const { return _length * _width; }
double Rectangle::perimeter() const { return (_length * 2) + (_width * 2); }
double Rectangle::length() const { return _length; }
double Rectangle::width() const { return _width; }
string Rectangle::name() const { return "Rectangle"; }