#include "Location.h"

Location::DIRECTION Location::direction(std::string const& dir) const{
	Location::DIRECTION result = NORTH;
	if (dir == "north"){ result = NORTH; }
	else if (dir == "east"){ result = EAST; }
	else if (dir == "south"){ result = SOUTH; }
	else if (dir == "west"){ result = WEST; }

	return result;
}