#ifndef __BUILDING_HPP__ 
#define __BUILDING_HPP__
#include "Unit.h"
#include <vector>
enum status{Not_build, Build, Upgraded};
class Building{
protected:
	//Units that building own
	std::vector<Unit> OWN;
	//Resourse array to build
	std::vector<int> REQUIRED_TO_BUILD; // 0-золото, 1-еда, 2-дерево, 3-камень, 4-св. люди, 5-занятые люди
	//Resourse array to upgrade
	std::vector<int> REQUIRED_TO_UPGRADE;
	//Status of the building
	status BUILDING_STATUS;
	//Resourses that building have
	std::vector<int> OBTAINED_RESOURSES;
public:
	//Building Constructor - create unbuilt building
	Building(){
		BUILDING_STATUS = Not_build;
		OBTAINED_RESOURSES = std::vector<int>(6);
		REQUIRED_TO_BUILD = std::vector<int>(6);
		REQUIRED_TO_UPGRADE = std::vector<int>(6);
	}
	//CHANGE_STATUS - change 
	void CHANGE_STATUS(status change_status = Build){
		BUILDING_STATUS = change_status;
	}
	//ADD_UNIT - add unit to the building (add_unit - unit to add)
	void ADD_UNIT(Unit add_unit){
		OWN.push_back(add_unit);
	}
	//GIVE_RESOURSES - return array of resourses that building is collected and delete them from building
	std::vector<int> GIVE_RESOURSES(){
		std::vector<int> temp = OBTAINED_RESOURSES;
		OBTAINED_RESOURSES = std::vector<int>(6);
		return temp;
	}
	//ADD_RESOURSES - add resuurses to the building
	void ADD_RESOURSES(std::vector<int> add_resourses){
		for (int i = 1; i != 7; i++){
			OBTAINED_RESOURSES[i] += add_resourses[i];
		}
	}
};
#endif