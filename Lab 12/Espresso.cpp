#include "Espresso.h"

Espresso::Espresso(string description) : Beverage(description) {}

double Espresso::cost() const { return 1.99; }