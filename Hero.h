#ifndef __HERO_H__ 
#define __HERO_H__
#include <string>
#include <vector>
#include "Tile.h"
#include "Map.h"
#include "Unit.h"
class Hero {
private:
	// Ќа какой клетке находитс€
	Tile pos;
	//  оличество шагов, на которое может пройти за ход
	int move;
	// ”ровень геро€
	int level;
	// »грок, к которому принадлежит
	std::string player;
	// ёниты, принадлежащие юниту (его арми€)
	std::vector<Unit> army;
	// Ѕонусы, оказываемые героем на армию !!!описание!!!
	std::vector<float> buff_army;
	// ќпыт геро€
	int exp;
	// Ѕонусы, оказываемые героем на ресурсы !!!описание!!!
	std::vector<float> buff_resource;
	// »м€ геро€
	std::string name;
	// ѕоле, на котором находитс€ в течении игры
	Map field;
public:
	/* онструктор Hero(
	Name - им€ геро€;
	field - поле, на котором он создан;
	x,y - его положение;
	player - им€ игрока, к которому принадлежит)*/
	Hero(std::string Name, Map Field, int x, int y, std::string Player);
	/*Get_x - получить x координату*/
	int Get_x();
	/*Get_y - получить x координату*/
	int Get_y();
	/*Print - напечатать состо€ние геро€ в консоль*/
	void Print();
	/*Move - сделать ход на 1 клетку, если это возможно(dir - направление хода )*/
	void Move(direction dir);
};
#endif