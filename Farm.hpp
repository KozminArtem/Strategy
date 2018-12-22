#ifndef __FARM_HPP__ 
#define __FARM_HPP__
#include "Building.hpp"
class Farm : public Building {
private:
	static Resource REQUIRED_TO_BUILD;
	static Resource REQUIRED_TO_UPGRADE;
	int SPEED_TO_CREATE_FOOD;
public:
	//Farm constructor
	Farm();
	//Upgrade - upgrade building (increase SPEED_TO_CREATE_FOOD to 100)
	void Upgrade();
	//Generate_resource - generate food at farm
	void Generate_resource();
};
#endif
