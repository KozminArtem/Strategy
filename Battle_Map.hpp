#ifndef __BATTLE_MAP_H__ 
#define __BATTLE_MAP_H__
#include "Map.hpp"
#include "Hero.hpp"
class Battle_Map : public Map {
private:
	//Hero 1 that located on the map
	Hero& HERO1;
	//Hero 2 that located on the map
	Hero& HERO2;
	//positions of Hero 1 units
	std::vector<Tile> MIL_POS1;
	//positions of Hero 2 units
	std::vector<Tile> MIL_POS2;
public:
	/* Battle_Map Constructor - create map from Tile array(size_X - x size of the map;
	size_Y - y size of the map)*/
	Battle_Map(std::vector<std::vector<Tile>> map_data, Hero& hero1, Hero& hero2);
	void Move_Unit(Military& unit, direction dir);
};
#endif