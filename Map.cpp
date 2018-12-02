#include "Map.h"
Map::Map(std::vector<std::vector<Tile>> map_data) {
	size_y = map_data.size();
	size_x = map_data[0].size();
	tile_array = map_data;
}
Map::Map(int size_X, int size_Y) {
	size_x = size_X;
	size_y = size_Y;
	std::vector<std::vector<Tile>> map_data;
	map_data.resize(size_y);
	for (int i = 1; i != size_y + 1; i++) {
		std::vector<Tile> v;
		v.resize(size_x);
		for (int j = 1; j != size_x + 1; j++) {
			v[j - 1] = Tile(j, i, plain);
		}
		map_data[i - 1] = v;
	}
	tile_array = map_data;
}
void Map::Print(std::ostream& out) {
	for (int i = size_y; i != 0; i--) {
		for (int j = 1; j != size_x + 1; j++) {
			tile_array[i - 1][j - 1].Print(out);
			if (j != size_x) out << " ";
		}
		out << "\n";
	}
}
int Map::Get_size_x() {
	return size_x;
}
int Map::Get_size_y() {
	return size_y;
}
Tile Map::Get_Tile(int x, int y) {
	if (1 <= x && x <= size_x && 1 <= y && y <= size_y) return tile_array[y - 1][x - 1];
    else{return false;}
}
