#include "Move.hpp"
void Move(direction dir, Map field, Tile &pos, int &move) {
	Tile nextpos;
	if (dir == direction::up) nextpos = field.Get_Tile(pos.Get_x(), pos.Get_y() + 1);
	if (dir == direction::down) nextpos = field.Get_Tile(pos.Get_x(), pos.Get_y() - 1);
	if (dir == direction::left) nextpos = field.Get_Tile(pos.Get_x() - 1, pos.Get_y());
	if (dir == direction::right) nextpos = field.Get_Tile(pos.Get_x() + 1, pos.Get_y());
	if (dir == direction::up_left) nextpos = field.Get_Tile(pos.Get_x() - 1, pos.Get_y() + 1);
	if (dir == direction::up_right) nextpos = field.Get_Tile(pos.Get_x() + 1, pos.Get_y() + 1);
	if (dir == direction::down_left) nextpos = field.Get_Tile(pos.Get_x() - 1, pos.Get_y() - 1);
	if (dir == direction::down_right) nextpos = field.Get_Tile(pos.Get_x() + 1, pos.Get_y() - 1);
	if (nextpos.Get_y() >= 1 && nextpos.Get_y() <= field.Get_size_y() && nextpos.Get_x() >= 1 && nextpos.Get_x() <= field.Get_size_x()) {
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
			if (move >= spend_move) {
				move -= spend_move;
				pos = nextpos;
			}
		}
	}
}