#include "Town_Hall.hpp"
Resource Town_Hall::REQUIRED_TO_BUILD = Resource(0, 0, 0, 100, 0);
Resource Town_Hall::REQUIRED_TO_UPGRADE = Resource(0, 1000, 1000, 1000, 0);
Town_Hall::Town_Hall() : Building(){
	SPEED_TO_CREATE_PEOPLE = 10;
}
void Town_Hall::Upgrade() {
	SPEED_TO_CREATE_PEOPLE = 15;
}
void Town_Hall::Generate_resource() {
	ADD_RESOURCES(Resource(0, 0, 0, 0, SPEED_TO_CREATE_PEOPLE));
}