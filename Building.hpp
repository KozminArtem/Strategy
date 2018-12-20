#ifndef __BUILDING_HPP__ 
#define __BUILDING_HPP__
#include "Unit.hpp"
#include <vector>
enum status{Not_build, Build, Upgraded};
class Building{
protected:
	//Units that building own
	std::vector<Unit> OWN;
	//Resource array to build
	std::vector<int> REQUIRED_TO_BUILD; // 1-food, 2-wood, 3-stone, 4-free people, 5-busy people
	//Resource array to upgrade
	std::vector<int> REQUIRED_TO_UPGRADE;
	//Status of the building
	status BUILDING_STATUS;
	//Resources that building have
	std::vector<int> OBTAINED_RESOURCES;
public:
	//Building Constructor - create unbuilt building
	Building(){
		BUILDING_STATUS = Not_build;
		OBTAINED_RESOURCES = std::vector<int>(6);
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
		std::vector<int> temp = OBTAINED_RESOURCES;
		OBTAINED_RESOURCES = std::vector<int>(6);
		return temp;
	}
	//ADD_RESOURSES - add resuurses to the building
	void ADD_RESOURSES(std::vector<int> add_resourses){
		for (int i = 1; i != 7; i++){
			OBTAINED_RESOURCES[i] += add_resourses[i];
		}
	}
};
#endif