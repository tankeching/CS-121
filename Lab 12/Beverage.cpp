#include "Beverage.h"

Beverage::Beverage(std::string description) : _description(description) {}

std::string Beverage::description() const { return _description; }

ostream& operator<<(ostream& os, Beverage const& bev){
	os << bev._description;
	return os;
}