#include "Town_Hall.hpp"
Town_Hall::Town_Hall() : Building(){
}
Resource Town_Hall::REQUIRED_TO_BUILD = Resource(0, 100, 100, 0, 0);
Resource Town_Hall::REQUIRED_TO_UPGRADE = Resource(0, 1000, 1000, 0, 0);