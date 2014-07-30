#include "Mocha.h"

Mocha::Mocha(const Beverage& beverage) : beverage(beverage){}

string Mocha::getDescription() const{
	return beverage.description() + ", Mocha";
}

double Mocha::cost() const{
	return 0.20 + beverage.cost();
}