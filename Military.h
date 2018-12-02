#ifndef __MILITARY_H__
#define __MILITARY_H__
#include "Unit.h"
#include "Hero.h"
class Military : public Unit{
protected:
	//герой, к которому принадлежит юнит
	Hero HERO;
	//скорость юнита
	int SPEED;
	//урон юнита
	int DAMAGE;
	//дистандия урона 1-ближники 2- дальники
	int TYPE_DAMAGE;
public:
	/*Конструктор Civilian( damage - урон юнита;
	type_damage - тип урона юнита;
	speed - скорость юнита;
	quantity - количество людей в отряде;
	health - здоровье 1 человека)*/
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
	/*GetDAMAGE - получить DAMAGE юнита*/
	int GetDAMAGE(void) const {
		return DAMAGE;
	}
	/*GetTYPE_DAMAGE - получить TYPE_DAMAGE юнита*/
	int GetTYPE_DAMAGE(void) const {
		return TYPE_DAMAGE;
	}
	/*GetSPEED - получить SPEED юнита*/
	int GetSPEED(void) const {
		return SPEED;
	}
	/*GetHERO - получить HERO юнита*/
	Hero GetHERO(void) const {
		return HERO;
	}
	/*SetDAMAGE - установить DAMAGE юнита*/
	void SetDAMAGE(int damage) {
		DAMAGE = damage;
	}
	/*SetTYPE_DAMAGE - установить TYPE_DAMAGE юнита*/
	void SetTYPE_DAMAGE(int type_damage) {
		TYPE_DAMAGE = type_damage;
	}
	/*SetSPEED - установить SPEED юнита*/
	void SetSPEED(int speed) {
		SPEED = speed;
	}
	/*SetHERO - установить HERO юнита*/
	void SetSPEED(Hero hero) {
		HERO = hero;
	}
	/*Squad_Reinforcement - добавить в отряд людей(Beginner - количество людей)*/
	virtual void Squad_Reinforcement(int Beginner) {
		SetQUANTITY(GetQUANTITY() + Beginner);
		SetSQUAD_HEALTH(GetSQUAD_HEALTH() + Beginner * GetHEALTH());
	}
	/*Squad_Departed - удалить из отряда людей(Departed_People - удаленные люди)*/
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
	/*Деструктор Military*/
	virtual ~Military() {
		std::cout << "Military died, in quantity " << GetQUANTITY() << std::endl;
	}
};
#endif