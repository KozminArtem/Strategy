#include "Battle_Map.hpp"
Battle_Map::Battle_Map(Hero* hero1, Hero* hero2) : Map(40, 20) {
	HERO1 = hero1;
	Army ARMY1(*HERO1);
	HERO1 = hero2;
	Army ARMY2(*HERO2);
}
void Battle_Map::Move_Unit(Army army, Military& unit, direction dir) {
	Tile nextpos;
	Tile &pos = army.Military_location(army.Find_Military(&unit));
	if (dir == direction::up) nextpos = Get_Tile(pos.Get_x(), pos.Get_y() + 1);
	if (dir == direction::down) nextpos = Get_Tile(pos.Get_x(), pos.Get_y() - 1);
	if (dir == direction::left) nextpos = Get_Tile(pos.Get_x() - 1, pos.Get_y());
	if (dir == direction::right) nextpos = Get_Tile(pos.Get_x() + 1, pos.Get_y());
	if (dir == direction::up_left) nextpos = Get_Tile(pos.Get_x() - 1, pos.Get_y() + 1);
	if (dir == direction::up_right) nextpos = Get_Tile(pos.Get_x() + 1, pos.Get_y() + 1);
	if (dir == direction::down_left) nextpos = Get_Tile(pos.Get_x() - 1, pos.Get_y() - 1);
	if (dir == direction::down_right) nextpos = Get_Tile(pos.Get_x() + 1, pos.Get_y() - 1);
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
			if (army.GetMove(&unit) >= spend_move) {
				army.SetMove(&unit, army.GetMove(&unit) - spend_move);
				army.SetTile(&unit, nextpos);
			}
		}
	}
}
void Battle_Map::Move_Unit_1(Military& unit, direction dir) {
	Move_Unit(ARMY1, unit, dir);
}
void Battle_Map::Move_Unit_2(Military& unit, direction dir) {
	Move_Unit(ARMY2, unit, dir);
}