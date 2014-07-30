#ifndef __DESIGNPATTERNS__DECAF_H__
#define __DESIGNPATTERNS__DECAF_H__

#include "Beverage.h"

class Decaf : public Beverage{
public:
	Decaf();
	Decaf(string description);
	double cost() const;
};

#endif