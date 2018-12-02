#ifndef __MILITARY_H__
#define __MILITARY_H__
#include "Unit.h"
#include "Hero.h"
class Military : public Unit{
protected:
	//�����, � �������� ����������� ����
	Hero HERO;
	//�������� �����
	int SPEED;
	//���� �����
	int DAMAGE;
	//��������� ����� 1-�������� 2- ��������
	int TYPE_DAMAGE;
public:
	/*����������� Civilian( damage - ���� �����;
	type_damage - ��� ����� �����;
	speed - �������� �����;
	quantity - ���������� ����� � ������;
	health - �������� 1 ��������)*/
	Military(Hero hero, int damage = 0, int type_damage = 0, int speed = 0, int quantity = 0, int health = 0) :Unit(quantity, health){
		DAMAGE = damage;
		TYPE_DAMAGE = type_damage;
		SPEED = speed;
		HERO = hero;
		std::cout << "Created new military unit.";
		std::cout << std::endl << "HEALTH of 1 person:" << HEALTH << std::endl;
		std::cout << "DAMAGE of unit:" << DAMAGE << std::endl;
		std::cout << "TYPE_DAMAGE of unit:" << TYPE_DAMAGE << std::endl;
		std::cout << "SPEED of unit:" << SPEED << std::endl;
		std::cout << "QUANTITY of people:" << QUANTITY << std::endl;
		std::cout << "SQUAD_HEALTH of unit:" << SQUAD_HEALTH << std::endl;
	}
	/*GetDAMAGE - �������� DAMAGE �����*/
	int GetDAMAGE(void) const {
		return DAMAGE;
	}
	/*GetTYPE_DAMAGE - �������� TYPE_DAMAGE �����*/
	int GetTYPE_DAMAGE(void) const {
		return TYPE_DAMAGE;
	}
	/*GetSPEED - �������� SPEED �����*/
	int GetSPEED(void) const {
		return SPEED;
	}
	/*GetHERO - �������� HERO �����*/
	Hero GetHERO(void) const {
		return HERO;
	}
	/*SetDAMAGE - ���������� DAMAGE �����*/
	void SetDAMAGE(int damage) {
		DAMAGE = damage;
	}
	/*SetTYPE_DAMAGE - ���������� TYPE_DAMAGE �����*/
	void SetTYPE_DAMAGE(int type_damage) {
		TYPE_DAMAGE = type_damage;
	}
	/*SetSPEED - ���������� SPEED �����*/
	void SetSPEED(int speed) {
		SPEED = speed;
	}
	/*SetHERO - ���������� HERO �����*/
	void SetSPEED(Hero hero) {
		HERO = hero;
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
	/*���������� Military*/
	virtual ~Military() {
		std::cout << "Military died, in quantity " << GetQUANTITY() << std::endl;
	}
};
#endif