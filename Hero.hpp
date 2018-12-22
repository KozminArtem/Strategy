#ifndef __HERO_H__ 
#define __HERO_H__
#include "Military.hpp"
#include <iostream>
#include <string>
#include <vector>
class Hero {
private:
	// X on which is located
	int x;
	// Y on which is located
	int y;
	// Number of tiles that hero can move on this turn
	int move_hero;
	// Hero level
	int level;
	// Player that have hero
	std::string player;
	// Hero army
	std::vector<Military> army;
	// Bonuses on army
	std::vector<float> buff_army;
	// Experience
	int exp;
	// Bonuses on resourses
	std::vector<float> buff_resource;
	// Hero name
	std::string name;
public:
	/*Hero Constructor(
	Name - hero name;
	field - map where hero located;
	x,y - his position;
	player - player that have hero)*/
	Hero(std::string Name, int X, int Y, std::string Player);
    Hero();
	/*Get_x - get x coordinate*/
	int Get_x();
	/*Get_y - get y coordinate*/
	int Get_y();
	/*Get_move - get move_hero coordinate*/
	int& Get_move();
	/*Set_x - set x coordinate*/
	void Set_x(int X);
	/*Set_y - set y coordinate*/
	void Set_y(int Y);
	/*Print - print hero status*/
	void Print();
	/* add_Unit - add unit to hero's army in vector army on last place(unit - unit to add)*/
	void add_Unit(Military unit);
	/*makes level bigger on 1 point*/
	void add_level();
	/*makes level bigger on 1 point*/
	void add_exp(int point);
	/* delete_Unit - delete last "Unit" in vector "army" */
	void delete_Unit();
};
#endif