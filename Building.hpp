#ifndef __BUILDING_HPP__ 
#define __BUILDING_HPP__
#include "Unit.hpp"
#include <vector>
#include "Resource.hpp"
class Building{
protected:
	//Units that building own
	std::vector<Unit> OWN;
	//Resource array to build
	Resource REQUIRED_TO_BUILD; // 1-food, 2-wood, 3-stone, 4-free people, 5-busy people
	//Resource array to upgrade
	Resource REQUIRED_TO_UPGRADE;
	//Resources that building have
	Resource OBTAINED_RESOURCES;
public:
	//Building Constructor - create unbuilt building
	Building(){
		Resource OBTAINED_RESOURCES();
		Resource REQUIRED_TO_BUILD();
		Resource REQUIRED_TO_UPGRADE();
	}
	//ADD_UNIT - add unit to the building (add_unit - unit to add)
	void ADD_UNIT(Unit add_unit){
		OWN.push_back(add_unit);
	}
	//GIVE_RESOURCES - return array of resourses that building is collected and delete them from building
	Resource GIVE_RESOURCES(){
		Resource temp = OBTAINED_RESOURCES;
		OBTAINED_RESOURCES = Resource();
		return temp;
	}
	//ADD_RESOURCES - add resuurses to the building
	void ADD_RESOURCES(Resource add_resourses){
		OBTAINED_RESOURCES = Resource(add_resourses.Wood() + OBTAINED_RESOURCES.Wood(), add_resourses.Food() + OBTAINED_RESOURCES.Food(), add_resourses.Stone() + OBTAINED_RESOURCES.Stone(), add_resourses.Free_people() + OBTAINED_RESOURCES.Free_people(), add_resourses.Busy_people() + OBTAINED_RESOURCES.Busy_people());
	}
};
#endif