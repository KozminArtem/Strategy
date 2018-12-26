#ifndef __ARMY_H__
#define __ARMY_H__
#include "Hero.hpp"
#include "Military.hpp"
#include "Tile.hpp"
#include <utility>
class Army {
private:
	//1 - Military unit, 2 - unit tile location, 3 - unit moves
	std::vector<std::pair<Military*,std::pair<Tile,int>>> MILILARY; 
public:
	//Army constructor
	Army(Hero& leader = Hero());
	Tile Military_location(std::pair<Military*, std::pair<Tile, int>> current_pair);
	std::pair<Military*, std::pair<Tile, int>>& Find_Military(Military* search);
	int GetMove(Military* search);
	void SetMove(Military* search, int move);
	void SetTile(Military* search, Tile tile);
};
#endif