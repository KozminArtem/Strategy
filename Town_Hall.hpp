#ifndef __TOWN_HALL_HPP__ 
#define __TOWN_HALL_HPP__
#include "Building.hpp"
class Town_Hall : public Building{
public:
	Town_Hall() : Building(){
		REQUIRED_TO_UPGRADE = { 1000, 100, 5000, 5000, 0, 0 };
	}
};
#endif