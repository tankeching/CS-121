#ifndef __DESIGNPATTERNS__CONDIMENTDECORATOR_H__
#define __DESIGNPATTERNS__CONDIMENTDECORATOR_H__

#include "Beverage.h"

class CondimentDecorator : public Beverage{
public:
	CondimentDecorator();
	CondimentDecorator(string description);

	virtual string getDescription() const = 0;
};

#endif