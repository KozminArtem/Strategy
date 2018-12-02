#ifndef __TILE_H__ 
#define __TILE_H__
#include <iostream>
#include <fstream>
enum tile_type { plain, forest, mountain, lake, river_horizontal, river_vertical, river_bridge_horizontal, river_bridge_vertical , hero};
class Tile {
private:
	int x;
	int y;
	tile_type type;
public:
	Tile(int pos_x = 0, int pos_y = 0, tile_type pos_type = plain);
	int Get_x();
	int Get_y();
	tile_type Get_type();
	void Set_x(int X);
	void Set_y(int Y);
	void Set_type(tile_type type);
	void Print(std::ostream& out = std::cout);
	bool is_passage();
};
#endif