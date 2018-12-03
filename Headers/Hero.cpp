#include "Declaration/Hero.hpp"
#include <iostream>
Hero::Hero(std::string Name, Map Field, int x, int y, std::string Player){
	name = Name;
	player = Player;
	pos = Field.Get_Tile(x, y);
	move = 3;
	level = 1;
	exp = 0;
	field = Field;
	army = std::vector<Unit>();
	buff_army = std::vector<float>();
	buff_resource = std::vector<float>();
}
Hero::Hero() {
}
int Hero::Get_x() {
	return pos.Get_x();
}
int Hero::Get_y() {
	return pos.Get_y();
}
void Hero::Move(direction dir) {
	if (dir == direction::up) {
		if (pos.Get_y() + 1 <= field.Get_size_y()) {
			if (field.Get_Tile(pos.Get_x(), pos.Get_y() + 1).is_passage()) {
				tile_type next = field.Get_Tile(pos.Get_x(), pos.Get_y() + 1).Get_type();
				if (next == forest && move >= 2) {
					move -= 2;
					pos = field.Get_Tile(pos.Get_x(), pos.Get_y() + 1);
				}
				if (next != forest && move >= 1) {
					move -= 1;
					pos = field.Get_Tile(pos.Get_x(), pos.Get_y() + 1);
				}
			}
		}
	}
	if (dir == direction::down) {
		if (pos.Get_y() - 1 >= 1) {
			if (field.Get_Tile(pos.Get_x(), pos.Get_y() - 1).is_passage()) {
				tile_type next = field.Get_Tile(pos.Get_x(), pos.Get_y() - 1).Get_type();
				if (next == forest && move >= 2) {
					move -= 2;
					pos = field.Get_Tile(pos.Get_x(), pos.Get_y() - 1);
				}
				if (next != forest && move >= 1) {
					move -= 1;
					pos = field.Get_Tile(pos.Get_x(), pos.Get_y() - 1);
				}
			}
		}
	}
	if (dir == direction::left) {
		if (pos.Get_x() - 1 >= 1) {
			if (field.Get_Tile(pos.Get_x() - 1, pos.Get_y()).is_passage()) {
				tile_type next = field.Get_Tile(pos.Get_x() - 1, pos.Get_y()).Get_type();
				if (next == forest && move >= 2) {
					move -= 2;
					pos = field.Get_Tile(pos.Get_x() - 1, pos.Get_y());
				}
				if (next != forest && move >= 1) {
					move -= 1;
					pos = field.Get_Tile(pos.Get_x() - 1, pos.Get_y());
				}
			}
		}
	}
	if (dir == direction::right) {
		if (pos.Get_x() + 1 <= field.Get_size_x()) {
			if (field.Get_Tile(pos.Get_x() + 1, pos.Get_y()).is_passage()) {
				tile_type next = field.Get_Tile(pos.Get_x() + 1, pos.Get_y()).Get_type();
				if (next == forest && move >= 2) {
					move -= 2;
					pos = field.Get_Tile(pos.Get_x() + 1, pos.Get_y());
				}
				if (next != forest && move >= 1) {
					move -= 1;
					pos = field.Get_Tile(pos.Get_x() + 1, pos.Get_y());
				}
			}
		}
	}
	if (dir == direction::up_left) {
		if (pos.Get_y() + 1 <= field.Get_size_y() && pos.Get_x() - 1 >= 1) {
			if (field.Get_Tile(pos.Get_x() - 1, pos.Get_y() + 1).is_passage()) {
				tile_type next = field.Get_Tile(pos.Get_x() - 1, pos.Get_y() + 1).Get_type();
				if (next == forest && move >= 3) {
					move -= 3;
					pos = field.Get_Tile(pos.Get_x() - 1, pos.Get_y() + 1);
				}
				if (next != forest && move >= 2) {
					move -= 2;
					pos = field.Get_Tile(pos.Get_x() - 1, pos.Get_y() + 1);
				}
			}
		}
	}
	if (dir == direction::up_right) {
		if (pos.Get_y() + 1 <= field.Get_size_y() && pos.Get_x() + 1 <= field.Get_size_x()) {
			if (field.Get_Tile(pos.Get_x() + 1, pos.Get_y() + 1).is_passage()) {
				tile_type next = field.Get_Tile(pos.Get_x() + 1, pos.Get_y() + 1).Get_type();
				if (next == forest && move >= 3) {
					move -= 3;
					pos = field.Get_Tile(pos.Get_x() + 1, pos.Get_y() + 1);
				}
				if (next != forest && move >= 2) {
					move -= 2;
					pos = field.Get_Tile(pos.Get_x() + 1, pos.Get_y() + 1);
				}
			}
		}
	}
	if (dir == direction::down_left) {
		if (pos.Get_y() - 1 >= 1 && pos.Get_x() - 1 >= 1) {
			if (field.Get_Tile(pos.Get_x() - 1, pos.Get_y() - 1).is_passage()) {
				tile_type next = field.Get_Tile(pos.Get_x() - 1, pos.Get_y() - 1).Get_type();
				if (next == forest && move >= 3) {
					move -= 3;
					pos = field.Get_Tile(pos.Get_x() - 1, pos.Get_y() - 1);
				}
				if (next != forest && move >= 2) {
					move -= 2;
					pos = field.Get_Tile(pos.Get_x() - 1, pos.Get_y() - 1);
				}
			}
		}
	}
	if (dir == direction::down_right) {
		if (pos.Get_y() - 1 >= 1 && pos.Get_x() + 1 <= field.Get_size_x()) {
			if (field.Get_Tile(pos.Get_x() + 1, pos.Get_y() - 1).is_passage()) {
				tile_type next = field.Get_Tile(pos.Get_x() + 1, pos.Get_y() - 1).Get_type();
				if (next == forest && move >= 3) {
					move -= 3;
					pos = field.Get_Tile(pos.Get_x() + 1, pos.Get_y() - 1);
				}
				if (next != forest && move >= 2) {
					move -= 2;
					pos = field.Get_Tile(pos.Get_x() + 1, pos.Get_y() - 1);
				}
			}
		}
	}
}
void Hero::Print() {
	std::cout << "Hero: " << name << std::endl;
	std::cout << "\tPlayer: " << player << std::endl;
	std::cout << "\tLevel: " << level << std::endl;
	std::cout << "\tExperience: " << exp << std::endl;
	std::cout << "\tMoves: " << move << std::endl;
	std::cout << "\tPosition x: " << pos.Get_x() << std::endl;
	std::cout << "\tPosition y: " << pos.Get_y() << std::endl;
}