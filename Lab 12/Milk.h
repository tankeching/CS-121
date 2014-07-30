#ifndef __DESIGNPATTERNS__MILK_H__
#define __DESIGNPATTERNS__MILK_H__

#include "CondimentDecorator.h"

class Milk : public CondimentDecorator{
private:
	const Beverage& beverage;

public:
	Milk(const Beverage& beverage);

	string getDescription() const;
	double cost() const;
};

#endif
