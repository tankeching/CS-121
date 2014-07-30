#include "Triangle.h"

#include <iostream>
#include <cmath>
using namespace std;

Triangle::Triangle() : _sideA(0), _sideB(0), _sideC(0){}
Triangle::Triangle(double sideA, double sideB, double sideC) : _sideA(sideA), _sideB(sideB), _sideC(sideC){}

void Triangle::sideA(double sideA){ _sideA = sideA; }
void Triangle::sideB(double sideB){ _sideB = sideB; }
void Triangle::sideC(double sideC){ _sideC = sideC; }

double Triangle::perimeter() const{ return _sideA + _sideB + _sideC; }
double Triangle::area() const{ return (_sideC * _sideB) / 2; }
double Triangle::length() const{ return _sideA; }
double Triangle::width() const{ return sqrt((_sideA * _sideA + _sideB * _sideB)); }
string Triangle::name() const{ return "Triangle"; }





