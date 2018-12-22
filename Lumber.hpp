#ifndef __LUMBER_HPP__ 
#define __LUMBER_HPP__
#include "Building.hpp"
class Lumber : public Building {
private:
	static Resource REQUIRED_TO_BUILD;
	static Resource REQUIRED_TO_UPGRADE;
	int SPEED_TO_CREATE_WOOD;
public:
	//Lumber constructor
	Lumber();
	//Upgrade - upgrade building (increase SPEED_TO_CREATE_WOOD to 50)
	void Upgrade();
	//Generate_resource - generate wood at lumber
	void Generate_resource();
};
#endif
