#include "Main_Map.hpp"
Main_Map::Main_Map(std::vector<std::vector<Tile>> map_data) : Map(map_data) {
	HEROES = std::vector<Hero*>();
}
Main_Map::Main_Map(int size_X, int size_Y) : Map(size_X, size_Y) {
	HEROES = std::vector<Hero*>();
}
void Main_Map::Add_Hero(Hero& add_hero) {
	HEROES.push_back(&add_hero);
}
void Main_Map::Move_Hero(Hero& hero, direction dir) {
	Tile nextpos;
	if (dir == direction::up) nextpos = Get_Tile(hero.Get_x(), hero.Get_y() + 1);
	if (dir == direction::down) nextpos = Get_Tile(hero.Get_x(), hero.Get_y() - 1);
	if (dir == direction::left) nextpos = Get_Tile(hero.Get_x() - 1, hero.Get_y());
	if (dir == direction::right) nextpos = Get_Tile(hero.Get_x() + 1, hero.Get_y());
	if (dir == direction::up_left) nextpos = Get_Tile(hero.Get_x() - 1, hero.Get_y() + 1);
	if (dir == direction::up_right) nextpos = Get_Tile(hero.Get_x() + 1, hero.Get_y() + 1);
	if (dir == direction::down_left) nextpos = Get_Tile(hero.Get_x() - 1, hero.Get_y() - 1);
	if (dir == direction::down_right) nextpos = Get_Tile(hero.Get_x() + 1, hero.Get_y() - 1);
	if (nextpos.Get_y() >= 1 && nextpos.Get_y() <= Get_size_y() && nextpos.Get_x() >= 1 && nextpos.Get_x() <= Get_size_x()) {
		if (nextpos.is_passage()) {
			int spend_move;
			if (dir == direction::up || dir == direction::down || dir == direction::left || dir == direction::right) {
				if (nextpos.Get_type() == forest) spend_move = 2;
				else spend_move = 1;
			}
			if (dir == direction::up_left || dir == direction::up_right || dir == direction::down_left || dir == direction::down_right) {
				if (nextpos.Get_type() == forest) spend_move = 3;
				else spend_move = 2;
			}
			if (hero.Get_move() >= spend_move) {
				hero.Get_move() -= spend_move;
				hero.Set_x(nextpos.Get_x());
				hero.Set_y(nextpos.Get_y());
			}
		}
	}
}