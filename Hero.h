#ifndef __HERO_H__ 
#define __HERO_H__
#include "Map.h"
#include "Unit.h"
#include "Move.hpp"
#include <iostream>
#include <string>
#include <vector>
class Hero {
private:
	// Tile on which is located
	Tile pos;
	// Number of tiles that hero can move on this turn
	int move_hero;
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
	/*Get_x - get x coordinate*/
	int Get_x();
	/*Get_y - get y coordinate*/
	int Get_y();
	/*Print - print hero status*/
	void Print();
	/*Move - make move on 1 tile(dir - direction of movement)*/
	void Move_Hero(direction dir);
	/* add_Unit - add unit to hero's army in vector army on last place(unit - unit to add)*/
	void add_Unit(Unit unit);
	/*makes level bigger on 1 point*/
	void add_level();
	/*makes level bigger on 1 point*/
	void add_exp();
	/* delete_Unit - delete last "Unit" in vector "army" */
	void delete_Unit();
};
#endif