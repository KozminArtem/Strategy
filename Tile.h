#ifndef __TILE_H__ 
#define __TILE_H__
#include <iostream>
#include <fstream>
/* Landscape type of the tile (plain; forest; mountain; lake; river_horizontal; river_vertical; river_bridge_horizontal; river_bridge_vertical)*/
enum tile_type { plain, forest, mountain, lake, river_horizontal, river_vertical, river_bridge_horizontal, river_bridge_vertical};
class Tile {
private:
	/* Tile x position*/
	int x;
	/* Tile y position*/
	int y;
	/* Tile landscape type*/
	tile_type type;
	/* Does this tile contains object*/
	bool is_placed;
public:
	/* Tile Constructor(pos_x - x position of the tile;
	pos_y - y position of the tile;
	pos_type - landscape of the tile)*/
	Tile(int pos_x = 0, int pos_y = 0, tile_type pos_type = plain);
	/* Get_x - get x position of the tile*/
	int Get_x();
	/* Get_y - get y position of the tile*/
	int Get_y();
	/* Get_type - get tile_type landscape of the tile*/
	tile_type Get_type();
	/* Set_x - set x position of the tile(X - position to set)*/
	void Set_x(int X);
	/* Set_y - set y position of the tile(Y - position to set)*/
	void Set_y(int Y);
	/* Set_type - set type of the tile(type - landscape to set)*/
	void Set_type(tile_type type);
	/* set - placed object on tile or not*/
	void Set_is_placed(bool is_pl = true);
	/* Print - print tile(out - stream to print (cout by default))*/
	void Print(std::ostream& out = std::cout);
	/* is_passage - True - hero can go trought tile; False - not*/
	bool is_passage();
	/* Get_is_placed - get - placed object on tile or not*/
	bool Get_is_placed();
};
#endif