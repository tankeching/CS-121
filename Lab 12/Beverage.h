#ifndef __DESIGNPATTERNS__BEVERAGE_H__
#define __DESIGNPATTERNS__BEVERAGE_H__

#include <iostream>
#include <string>
using namespace std;

class Beverage{
public:
	Beverage(string description);

	virtual std::string description() const;
	double virtual cost() const = 0;

	friend std::ostream& operator<<(std::ostream& os, Beverage const& bev);

private:
	std::string _description;
};

#endif