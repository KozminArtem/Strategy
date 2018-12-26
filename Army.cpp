#include "Army.hpp"
Army::Army(Hero& leader) {
	MILILARY = std::vector<std::pair<Military*, std::pair<Tile, int>>>();
	for (auto i = leader.Get_Army().begin(); i != leader.Get_Army().end(); i++) {
		std::pair<Tile, int> temp(Tile(),10);
		MILILARY.push_back(std::pair<Military*, std::pair<Tile, int>>((*i),temp));
	}
}
Tile Army::Military_location(std::pair<Military*, std::pair<Tile, int>> current_pair) {
	return current_pair.second.first;
}
std::pair<Military*, std::pair<Tile, int>>& Army::Find_Military(Military* search) {
	for (auto i = MILILARY.begin(); i != MILILARY.end(); i++) {
		if (i->first == search) return (*i);
	}
}
int Army::GetMove(Military* search) {
	return Find_Military(search).second.second;
}
void Army::SetMove(Military* search, int move) {
	Find_Military(search).second.second = move;
}
void Army::SetTile(Military* search, Tile tile) {
	Find_Military(search).second.first = tile;
}