#ifndef __Unit_H__ 
#define __Unit_H__
#include <iostream>
#include <string>
class Unit {
protected:
	//���� �����
	int DAMAGE;
	//��������� ����� 1-�������� 2- ��������
	int TYPE_DAMAGE;
	//�������� �����
	int SPEED;
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
	Unit(int damage = 0, int type_damage = 0, int speed = 0, int quantity = 0, int health = 0) : DAMAGE(damage), TYPE_DAMAGE(type_damage), SPEED(speed), QUANTITY(quantity), HEALTH(health){
		SQUAD_HEALTH = QUANTITY * HEALTH;
	}
	/*GetHEALTH - �������� HEALTH �����*/
	int GetHEALTH(void) const { 
		return HEALTH;
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
	virtual void Squad_Departed(size_t Departed_People) {
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