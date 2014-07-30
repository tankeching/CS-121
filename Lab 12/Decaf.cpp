#include "Decaf.h"

Decaf::Decaf(string description) : Beverage(description) {}

double Decaf::cost() const { return 1.05; }