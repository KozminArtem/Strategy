#include "Hero.hpp"
Hero::Hero(std::string Name, int X, int Y, std::string Player){
	name = Name;
	player = Player;
	x = X;
	y = Y;
	move_hero = 10;
	level = 1;
	exp = 0;
	army = std::vector<Military>();
	buff_army = std::vector<float>();
	buff_resource = std::vector<float>();
}
Hero::Hero(){};
int Hero::Get_x() {
	return x;
}
int Hero::Get_y() {
	return y;
}
int& Hero::Get_move() {
	return move_hero;
}
void Hero::Set_x(int X) {
	x = X;
}
void Hero::Set_y(int Y) {
	y = Y;
}
void Hero::Print() {
	std::cout << "Hero: " << name << std::endl;
	std::cout << "\tPlayer: " << player << std::endl;
	std::cout << "\tLevel: " << level << std::endl;
	std::cout << "\tExperience: " << exp << std::endl;
	std::cout << "\tMoves: " << move_hero << std::endl;
	std::cout << "\tPosition x: " << x << std::endl;
	std::cout << "\tPosition y: " << y << std::endl;
}
void Hero::add_Unit(Military unit) {
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