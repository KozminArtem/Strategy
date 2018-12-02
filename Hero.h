#ifndef __HERO_H__ 
#define __HERO_H__
#include <string>
#include <vector>
#include "Tile.h"
#include "Map.h"
#include "Unit.h"
class Hero {
private:
	// Tile on which is located
	Tile pos;
	// Number of tiles that hero can move on this turn
	int move;
	// Hero level
	int level;
	// Player that have hero
	std::string player;
	// Hero army
	std::vector<Unit> army;
	// Bonuses on army
	std::vector<float> buff_army;
	// Experience
	int exp;
	// Bonuses on resourses
	std::vector<float> buff_resource;
	// Hero name
	std::string name;
	// Field where hero located
	Map field;
public:
	/*Hero Constructor(
	Name - hero name;
	field - map where hero located;
	x,y - his position;
	player - player that have hero)*/
	Hero(std::string Name, Map Field, int x, int y, std::string Player);
	/*Hero Constructor*/
	Hero();
	/*Get_x - get x coordinate*/
	int Get_x();
	/*Get_y - get y coordinate*/
	int Get_y();
	/*Print - print hero status*/
	void Print();
	/*Move - make move on 1 tile(dir - direction of movement)*/
	void Move(direction dir);
};
#endif