#ifndef __Unit_H__ 
#define __Unit_H__
#include <iostream>
#include <string>
class Unit {
protected:
	//���������� ����� � ������
	int QUANTITY;
	//�������� 1-�� ��������
	int HEALTH;
	//���������� �������� �� ��� ������
	int SQUAD_HEALTH;
public:
	/*����������� Unit( damage - ���� �����;
	type_damage - ��� ����� �����;
	speed - �������� �����;
	quantity - ���������� ����� � ������;
	health - �������� 1 ��������)*/
	Unit(int quantity = 0, int health = 0){
		QUANTITY = quantity; 
		HEALTH = health;
		SQUAD_HEALTH = QUANTITY * HEALTH;
	}
	/*GetHEALTH - �������� HEALTH �����*/
	int GetHEALTH(void) const { 
		return HEALTH;
	}
	/*GetQUANTITY - �������� QUANTITY �����*/
	int GetQUANTITY(void) const {
		return QUANTITY;
	}
	/*GetSQUAD_HEALTH - �������� SQUAD_HEALTH �����*/
	int GetSQUAD_HEALTH(void) const {
		return SQUAD_HEALTH;
	}
	/*SetHEALTH - ���������� HEALTH �����*/
	void SetHEALTH(int health) {
		HEALTH = health;
	}
	/*SetQUANTITY - ���������� QUANTITY �����*/
	void SetQUANTITY(int quantity) {
		QUANTITY = quantity;
	}
	/*SetSQUAD_HEALTH - ���������� SQUAD_HEALTH �����*/
	void SetSQUAD_HEALTH(int squad_health) {
		SQUAD_HEALTH = squad_health;
	}
	/*Squad_Reinforcement - �������� � ����� �����(Beginner - ���������� �����)*/
	virtual void Squad_Reinforcement(int Beginner) {
		QUANTITY = QUANTITY + Beginner;
		SQUAD_HEALTH = SQUAD_HEALTH + Beginner * HEALTH;
	}
	/*Squad_Departed - ������� �� ������ �����(Departed_People - ��������� ����)*/
	virtual void Squad_Departed(int Departed_People) {
		if (Departed_People < QUANTITY) {
			QUANTITY = QUANTITY - Departed_People;
			SQUAD_HEALTH = SQUAD_HEALTH - Departed_People * HEALTH;
		}
		else {
			QUANTITY = 0;
			SQUAD_HEALTH = 0;
		}
	}
	/*���������� Unit*/
	virtual ~Unit() {
	}
};
#endif