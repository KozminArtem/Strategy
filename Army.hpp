#ifndef __ARMY_H__
#define __ARMY_H__
#include "Hero.hpp"
#include "Military.hpp"
#include "Tile.hpp"
#include <utility>
class Army {
private:
	std::vector<std::pair< Military&, Tile>> MILILARY;
public:
	//Army constructor
	Army(Hero leader);
	Tile Military_location(Military unit);
};
#endif