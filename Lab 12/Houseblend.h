#ifndef __DESIGNPATTERNS__HOUSEBLEND_H__
#define __DESIGNPATTERNS__HOUSEBLEND_H__

#include "Beverage.h"

class HouseBlend : public Beverage{
public:
	HouseBlend();
	HouseBlend(string description);
	double cost() const;
};

#endif