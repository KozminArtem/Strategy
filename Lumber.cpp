#include "Lumber.hpp"
Resource Lumber::REQUIRED_TO_BUILD = Resource(0, 50, 50, 50, 0);
Resource Lumber::REQUIRED_TO_UPGRADE = Resource(0, 700, 700, 700, 0);
Lumber::Lumber() : Building() {
	SPEED_TO_CREATE_WOOD = 25;
}
void Lumber::Upgrade() {
	SPEED_TO_CREATE_WOOD = 50;
}
void Lumber::Generate_resource() {
	ADD_RESOURCES(Resource(0, SPEED_TO_CREATE_WOOD, 0, 0, 0));
}