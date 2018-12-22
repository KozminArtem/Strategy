#ifndef __MAIN_MAP_H__ 
#define __MAIN_MAP_H__
#include "Map.hpp"
#include "Hero.hpp"
class Main_Map : public Map {
private:
	//Heroes that located on the map
	std::vector<Hero> HEROES;
public:
	/* Main_Map Constructor - create map with all tiles - plains(size_X - x size of the map;
	size_Y - y size of the map)*/
	Main_Map(int size_X = 1, int size_Y = 1);
	/* Main_Map Constructor - create map from Tile array(size_X - x size of the map;
	size_Y - y size of the map)*/
	Main_Map(std::vector<std::vector<Tile>> map_data);
	void Add_Hero(Hero add_hero);
	void Move_Hero(Hero& hero, direction dir);
};
#endif