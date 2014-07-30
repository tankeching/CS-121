#ifndef __DESIGNPATTERNS__SOY_H__
#define __DESIGNPATTERNS__SOY_H__

#include "CondimentDecorator.h"

class Soy : public CondimentDecorator{
private:
	const Beverage& beverage;

public:
	Soy(const Beverage& beverage);

	string getDescription() const;
	double cost() const;

};

#endif