#ifndef __MAP_H__ 
#define __MAP_H__
#include <string>
#include <vector>
#include "Tile.h"
#include "Map.h"
#include "Unit.h"
class Hero {
	Tile pos; // �� ����� ������ ���������
	int move; // ���������� �����, �� ������� ����� ������
	int level; // ������� �����
	std::string Player; // �����, � �������� �����������
	std::vector<Unit> Army; // �����, ������������� ����� (��� �����)
	std::vector<float> Buff_army; // ������, ����������� ������ �� ����� !!!��������!!!
	int exp; // ���� �����
	std::vector<float> Buff_resource; // ������, ����������� ������ �� ������� !!!��������!!!
	std::string Name; // ��� �����
	void Turn(dir direction);
};
#endif