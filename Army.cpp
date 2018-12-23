#include "Army.hpp"
Army::Army(Hero& leader) {
	std::vector<std::pair< Military&, Tile>> MILILARY;
	for (auto i = leader.Get_Army().begin(); i != leader.Get_Army().end(); i++) {
		MILILARY.push_back(std::pair< Military&, Tile>((*i),Tile()));
	}
}
Tile Army::Military_location(std::pair< Military&, Tile> current_pair) {
	return current_pair.second;
}