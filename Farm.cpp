#include "Farm.hpp"
Resource Farm::REQUIRED_TO_BUILD = Resource(0, 50, 50, 50, 0);
Resource Farm::REQUIRED_TO_UPGRADE = Resource(0, 700, 700, 700, 0);
Farm::Farm() : Building() {
	SPEED_TO_CREATE_FOOD = 50;
}
void Farm::Upgrade() {
	SPEED_TO_CREATE_FOOD = 100;
}
void Farm::Generate_resource() {
	ADD_RESOURCES(Resource(SPEED_TO_CREATE_FOOD, 0, 0, 0, 0));
}