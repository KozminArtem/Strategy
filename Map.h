#ifndef __MAP_H__ 
#define __MAP_H__
#include <vector>
#include <iostream>
#include <fstream>
#include "Tile.h"
/* Direction (left; right; up; down; up_left; up_right; down_left; down_right)*/
enum class direction { left, right, up, down, up_left, up_right, down_left, down_right };
class Map {
private:
	/* tile_array - array of the tiles*/
	std::vector<std::vector<Tile>> tile_array;
	/* size_x - x size of the map*/
	int size_x;
	/* size_y - y size of the map*/
	int size_y;
public:
	/* Map Constructor - create map with all tiles - plains(size_X - x size of the map;
	size_Y - y size of the map)*/
	Map(int size_X = 1, int size_Y = 1);
	/* Map Constructor - create map from Tile array(size_X - x size of the map;
	size_Y - y size of the map)*/
	Map(std::vector<std::vector<Tile>> map_data);
	/* Print - print map(out - stream to print (cout by default))*/
	void Print(std::ostream& out = std::cout);
	/* Get_size_x - get x size of the map*/
	int Get_size_x();
	/* Get_size_y - get y size of the map*/
	int Get_size_y();
	/* Get_Tile - get tile with coordinates(x - x position of the tile;
	y - y position of the tile)*/
	Tile Get_Tile(int x, int y);

};
#endif