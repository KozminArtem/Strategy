#ifndef __CIVILIAN_H__ 
#define __CIVILIAN_H__
#include "Unit.h"
class Civilian : public Unit{
public:
	/*����������� Civilian( damage - ���� �����;
	type_damage - ��� ����� �����;
	speed - �������� �����;
	quantity - ���������� ����� � ������;
	health - �������� 1 ��������)*/
	Civilian(int quantity = 0, int health = 0) : Unit(quantity, health)
	{
		std::cout << "Created new civilian unit.";
		std::cout << std::endl << "HEALTH of 1 person:" << HEALTH << std::endl;
		std::cout << "QUANTITY of people:" << QUANTITY << std::endl;
		std::cout << "SQUAD_HEALTH of unit:" << SQUAD_HEALTH << std::endl;
	}
	/*Squad_Reinforcement - �������� � ����� �����(Beginner - ���������� �����)*/
	virtual void Squad_Reinforcement(int Beginner) {
		SetQUANTITY(GetQUANTITY() + Beginner);
		SetSQUAD_HEALTH(GetSQUAD_HEALTH() + Beginner * GetHEALTH());
	}
	/*Squad_Departed - ������� �� ������ �����(Departed_People - ��������� ����)*/
	virtual void Squad_Departed(int Departed_People) {
		if (Departed_People < GetQUANTITY()) {
			SetQUANTITY(GetQUANTITY() - Departed_People);
			SetSQUAD_HEALTH(GetSQUAD_HEALTH() - Departed_People * GetHEALTH());
		}
		else {
			SetQUANTITY(0);
			SetSQUAD_HEALTH(0);
		}
	}
	/*���������� Civilian*/
	virtual ~Civilian() {
		std::cout << "Civilians died, in quantity " << GetQUANTITY() << std::endl;
	}
};
#endif