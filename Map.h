#ifndef __MAP_H__ 
#define __MAP_H__
#include <vector>
#include <iostream>
#include <fstream>
#include "Tile.h"
enum class direction { left, right, up, down, up_left, up_right, down_left, down_right };
class Map {
private:
	std::vector<std::vector<Tile>> tile_array;
	int size_x;
	int size_y;
public:
	Map(int size_X = 1, int size_Y = 1);
	Map(std::vector<std::vector<Tile>> map_data);
	void Print(std::ostream& out = std::cout);
	int Get_size_x();
	int Get_size_y();
	Tile Get_Tile(int x, int y);

};
#endif