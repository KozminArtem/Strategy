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
	Building();
	//ADD_UNIT - add unit to the building (add_unit - unit to add)
	void ADD_UNIT(Unit add_unit);
	//GIVE_RESOURCES - return array of resourses that building is collected and delete them from building
	Resource GIVE_RESOURCES();
	//ADD_RESOURCES - add resuurses to the building
	void ADD_RESOURCES(Resource add_resourses);
};
#endif