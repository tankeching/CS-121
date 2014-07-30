#include "Whip.h"

Whip::Whip(const Beverage& beverage) : beverage(beverage){}

string Whip::getDescription() const{
	return beverage.description() + ", Whip";
}

double Whip::cost() const{
	return 0.10 + beverage.cost();
}