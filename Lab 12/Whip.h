#ifndef __DESIGNPATTERNS__WHIP_H__
#define __DESIGNPATTERNS__WHIP_H__

#include "CondimentDecorator.h"

class Whip : public CondimentDecorator{
private:
	const Beverage& beverage;

public:
	Whip(const Beverage& beverage);

	string getDescription() const;
	double cost() const;

};

#endif