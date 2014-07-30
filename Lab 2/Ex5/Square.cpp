#include <cmath>
#include "Square.h"

Square::Square() : _side(0){}
Square::Square(double side) : Rectangle(side,side){}

void Square::side(double side){
	_side = side;
	length(side);
	width(side);
}

double Square::side() const{ return _side; }

string Square::name() const{ return "Square"; }


