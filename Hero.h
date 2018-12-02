#ifndef __HERO_H__ 
#define __HERO_H__
#include <string>
#include <vector>
#include "Tile.h"
#include "Map.h"
#include "Unit.h"
class Hero {
private:
	// �� ����� ������ ���������
	Tile pos;
	// ���������� �����, �� ������� ����� ������ �� ���
	int move;
	// ������� �����
	int level;
	// �����, � �������� �����������
	std::string player;
	// �����, ������������� ����� (��� �����)
	std::vector<Unit> army;
	// ������, ����������� ������ �� ����� !!!��������!!!
	std::vector<float> buff_army;
	// ���� �����
	int exp;
	// ������, ����������� ������ �� ������� !!!��������!!!
	std::vector<float> buff_resource;
	// ��� �����
	std::string name;
	// ����, �� ������� ��������� � ������� ����
	Map field;
public:
	/*����������� Hero(
	Name - ��� �����;
	field - ����, �� ������� �� ������;
	x,y - ��� ���������;
	player - ��� ������, � �������� �����������)*/
	Hero(std::string Name, Map Field, int x, int y, std::string Player);
	/*Get_x - �������� x ����������*/
	int Get_x();
	/*Get_y - �������� x ����������*/
	int Get_y();
	/*Print - ���������� ��������� ����� � �������*/
	void Print();
	/*Move - ������� ��� �� 1 ������, ���� ��� ��������(dir - ����������� ���� )*/
	void Move(direction dir);
};
#endif