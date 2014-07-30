#ifndef __DESIGNPATTERNS__MOCHA_H__
#define __DESIGNPATTERNS__MOCHA_H__

#include "CondimentDecorator.h"

class Mocha : public CondimentDecorator{
private:
	const Beverage& beverage;

public:
	Mocha(const Beverage& beverage);

	string getDescription() const;
	double cost() const;
};

#endif