#ifndef __MAP_H__ 
#define __MAP_H__
#include <string>
#include <vector>
#include "Tile.h"
#include "Map.h"
#include "Unit.h"
class Hero {
	Tile pos; // На какой клетке находится
	int move; // Количество шагов, на которое может пройти
	int level; // Уровень героя
	std::string Player; // Игрок, к которому принадлежит
	std::vector<Unit> Army; // Юниты, принадлежащие юниту (его армия)
	std::vector<float> Buff_army; // Бонусы, оказываемые героем на армию !!!описание!!!
	int exp; // Опыт героя
	std::vector<float> Buff_resource; // Бонусы, оказываемые героем на ресурсы !!!описание!!!
	std::string Name; // Имя героя
	void Turn(dir direction);
};
#endif