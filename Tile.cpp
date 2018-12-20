#include "Tile.hpp"
Tile::Tile(int pos_x, int pos_y, tile_type pos_type) {
	x = pos_x;
	y = pos_y;
	type = pos_type;
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
void Tile::Set_x(int X) {
	x = X;
}
void Tile::Set_y(int Y) {
	y = Y;
}
void Tile::Set_type(tile_type Type) {
	type = Type;
}
void Tile::Print(std::ostream& out) {
	out << type;
}
bool Tile::is_passage() {
	if (type == mountain || type == lake || type == river_horizontal || type == river_bridge_vertical) return false;
	else return true;
}