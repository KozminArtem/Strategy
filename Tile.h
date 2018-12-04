#ifndef __TILE_H__ 
#define __TILE_H__
#include <iostream>
#include <fstream>
enum tile_type { plain, forest, mountain, lake, river_horizontal, river_vertical, river_bridge_horizontal, river_bridge_vertical};
class Tile {
private:
	int x;
	int y;
	tile_type type;
	bool is_placed;
public:
	Tile(int pos_x = 0, int pos_y = 0, tile_type pos_type = plain);
	int Get_x();
	int Get_y();
	tile_type Get_type();
	bool Tile::Get_is_placed();
	void Set_x(int X);
	void Set_y(int Y);
	void Set_type(tile_type type);
	void Set_type(bool is_pl = true);
	void Print(std::ostream& out = std::cout);
	bool is_passage();
};
#endif