#ifndef __ZorkProject__Location__
#define __ZorkProject__Location__

#include <iostream>
#include <string>

class Location{
public:
	enum DIRECTION{ NORTH, EAST, SOUTH, WEST };
	Location::DIRECTION direction(std::string const& dir) const;
private:
};

#endif