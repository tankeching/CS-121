#include "Soy.h"

Soy::Soy(const Beverage& beverage) : beverage(beverage){}

string Soy::getDescription() const{
	return beverage.description() + ", Soy";
}

double Soy::cost() const{
	return 0.15 + beverage.cost();
}