#ifndef __TOWN_HALL_HPP__ 
#define __TOWN_HALL_HPP__
#include "Building.hpp"
class Town_Hall : public Building{
private:
	static Resource REQUIRED_TO_BUILD;
	static Resource REQUIRED_TO_UPGRADE;
	int SPEED_TO_CREATE_PEOPLE;
public:
	//Town_Hall constructor
	Town_Hall();
	//Upgrade - upgrade building (increase SPEED_TO_CREATE_PEOPLE to 15)
	void Upgrade();
	//Generate_resource - generate free people at town hall
	void Generate_resource();
};
#endif