#include "Hero.h"
Hero::Hero(std::string Name, Map Field, int x, int y, std::string Player){
	name = Name;
	player = Player;
	pos = Field.Get_Tile(x, y);
	move_hero = 3;
	level = 1;
	exp = 0;
	field = Field;
	pos.Set_is_placed(true);
	army = std::vector<Unit>();
	buff_army = std::vector<float>();
	buff_resource = std::vector<float>();
}
int Hero::Get_x() {
	return pos.Get_x();
}
int Hero::Get_y() {
	return pos.Get_y();
}
void Hero::Move_Hero(direction dir) {
	Move(dir, field, pos, move_hero);
}
void Hero::Print() {
	std::cout << "Hero: " << name << std::endl;
	std::cout << "\tPlayer: " << player << std::endl;
	std::cout << "\tLevel: " << level << std::endl;
	std::cout << "\tExperience: " << exp << std::endl;
	std::cout << "\tMoves: " << move_hero << std::endl;
	std::cout << "\tPosition x: " << pos.Get_x() << std::endl;
	std::cout << "\tPosition y: " << pos.Get_y() << std::endl;
}
void Hero::add_Unit(Unit unit) {
	army.push_back(unit);
}
void Hero::add_level()
{
	level += 1;
}
void Hero::add_exp(int point)
{
	exp += point;
}
void Hero::delete_Unit()
{
	army.pop_back();
}