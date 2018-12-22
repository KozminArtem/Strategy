#ifndef __MINE_HPP__ 
#define __MINE_HPP__
#include "Building.hpp"
class Mine : public Building {
private:
	static Resource REQUIRED_TO_BUILD;
	static Resource REQUIRED_TO_UPGRADE;
	int SPEED_TO_CREATE_IRON;
public:
	//Mine constructor
	Mine();
	//Upgrade - upgrade building (increase SPEED_TO_CREATE_IRON to 50)
	void Upgrade();
	//Generate_resource - generate iron at mine
	void Generate_resource();
};
#endif