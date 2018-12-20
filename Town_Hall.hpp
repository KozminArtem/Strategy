#ifndef __TOWN_HALL_HPP__ 
#define __TOWN_HALL_HPP__
#include "Building.hpp"
class Town_Hall : public Building{
private:
	static Resource REQUIRED_TO_BUILD;
	static Resource REQUIRED_TO_UPGRADE;
public:
	Town_Hall();
};
#endif