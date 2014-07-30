#include "DarkRoast.h"

DarkRoast::DarkRoast(string description) : Beverage(description) {}

double DarkRoast::cost() const{ return 0.99; }