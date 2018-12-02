#ifndef __Unit_H__ 
#define __Unit_H__
#include <iostream>
#include <string>
class Unit {
protected:
	//количество людей в отряде
	int QUANTITY;
	//здоровье 1-го человека
	int HEALTH;
	//количество здоровья во всём отряде
	int SQUAD_HEALTH;
public:
	/*Конструктор Unit( damage - урон юнита;
	type_damage - тип урона юнита;
	speed - скорость юнита;
	quantity - количество людей в отряде;
	health - здоровье 1 человека)*/
	Unit(int quantity = 0, int health = 0){
		QUANTITY = quantity; 
		HEALTH = health;
		SQUAD_HEALTH = QUANTITY * HEALTH;
	}
	/*GetHEALTH - получить HEALTH юнита*/
	int GetHEALTH(void) const { 
		return HEALTH;
	}
	/*GetQUANTITY - получить QUANTITY юнита*/
	int GetQUANTITY(void) const {
		return QUANTITY;
	}
	/*GetSQUAD_HEALTH - получить SQUAD_HEALTH юнита*/
	int GetSQUAD_HEALTH(void) const {
		return SQUAD_HEALTH;
	}
	/*SetHEALTH - установить HEALTH юнита*/
	void SetHEALTH(int health) {
		HEALTH = health;
	}
	/*SetQUANTITY - установить QUANTITY юнита*/
	void SetQUANTITY(int quantity) {
		QUANTITY = quantity;
	}
	/*SetSQUAD_HEALTH - установить SQUAD_HEALTH юнита*/
	void SetSQUAD_HEALTH(int squad_health) {
		SQUAD_HEALTH = squad_health;
	}
	/*Squad_Reinforcement - добавить в отряд людей(Beginner - количество людей)*/
	virtual void Squad_Reinforcement(int Beginner) {
		QUANTITY = QUANTITY + Beginner;
		SQUAD_HEALTH = SQUAD_HEALTH + Beginner * HEALTH;
	}
	/*Squad_Departed - удалить из отряда людей(Departed_People - удаленные люди)*/
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
	/*Деструктор Unit*/
	virtual ~Unit() {
	}
};
#endif