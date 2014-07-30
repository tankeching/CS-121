#include "Milk.h"

Milk::Milk(const Beverage& beverage) : beverage(beverage){}

string Milk::getDescription() const{
	return beverage.description() + ", Milk";
}

double Milk::cost() const{
	return 0.10 + beverage.cost();
}