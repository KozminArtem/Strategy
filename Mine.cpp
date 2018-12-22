#include "Mine.hpp"
Resource Mine::REQUIRED_TO_BUILD = Resource(0, 50, 50, 50, 0);
Resource Mine::REQUIRED_TO_UPGRADE = Resource(0, 700, 700, 700, 0);
Mine::Mine() : Building() {
	SPEED_TO_CREATE_IRON = 25;
}
void Mine::Upgrade() {
	SPEED_TO_CREATE_IRON = 50;
}
void Mine::Generate_resource() {
	ADD_RESOURCES(Resource(0, 0, SPEED_TO_CREATE_IRON, 0, 0));
}