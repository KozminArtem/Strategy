#include "Tile.h"
Tile::Tile(int pos_x, int pos_y, tile_type pos_type) {
	x = pos_x;
	y = pos_y;
	type = pos_type;
	is_placed = false;
}
int Tile::Get_x() {
	return x;
}
int Tile::Get_y() {
	return y;
}
tile_type Tile::Get_type() {
	return type;
}
bool Tile::Get_is_placed() {
	return is_placed;
}
void Tile::Set_x(int X) {
	x = X;
}
void Tile::Set_y(int Y) {
	y = Y;
}
void Tile::Set_type(tile_type Type) {
	type = Type;
}
void Tile::Set_type(bool is_pl) {
	is_placed = is_pl;
}
void Tile::Print(std::ostream& out) {
	out << type;
}
bool Tile::is_passage() {
	if (type == mountain || type == lake || type == river_horizontal || type == river_bridge_vertical) return false;
	else return true;
}