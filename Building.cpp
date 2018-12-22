#include "Building.hpp"
Building::Building() {
	Resource OBTAINED_RESOURCES();
	Resource REQUIRED_TO_BUILD();
	Resource REQUIRED_TO_UPGRADE();
}
void Building::ADD_UNIT(Unit add_unit) {
	OWN.push_back(add_unit);
}
Resource Building::GIVE_RESOURCES() {
	Resource temp = OBTAINED_RESOURCES;
	OBTAINED_RESOURCES = Resource();
	return temp;
}
void Building::ADD_RESOURCES(Resource add_resourses) {
	OBTAINED_RESOURCES = add_resourses + OBTAINED_RESOURCES;
}