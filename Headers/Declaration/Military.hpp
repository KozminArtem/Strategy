#ifndef __MILITARY_HPP__
#define __MILITARY_HPP__
#include "Unit.hpp"
#include "Hero.hpp"
#include "Map.hpp"
class Military : public Unit {
protected:
	//Hero that have unit
	Hero HERO;
	//Unit speed
	int SPEED;
	//Unit damage
	int DAMAGE;
	//Damage distanse (1 - close-combat,2 - long range)
	int TYPE_DAMAGE;
	//Map position
	Tile pos;
	//Bonuses that depends on enemy

public:
	/*Military Constructor(hero - hero that have unit;
	damage - unit damage;
	type_damage - damage distanse;
	speed - unit speed;
	quantity - number of people;
	health - healthof 1 person)*/
	Military(Hero hero, int damage = 0, int type_damage = 0, int speed = 0, int quantity = 0, int health = 0) :Unit(quantity, health) {
		DAMAGE = damage;
		TYPE_DAMAGE = type_damage;
		SPEED = speed;
		HERO = hero;
		pos = Tile(0, 0);
		std::cout << "Created new military unit.";
		std::cout << std::endl << "HEALTH of 1 person:" << HEALTH << std::endl;
		std::cout << "DAMAGE of unit:" << DAMAGE << std::endl;
		std::cout << "TYPE_DAMAGE of unit:" << TYPE_DAMAGE << std::endl;
		std::cout << "SPEED of unit:" << SPEED << std::endl;
		std::cout << "QUANTITY of people:" << QUANTITY << std::endl;
		std::cout << "SQUAD_HEALTH of unit:" << SQUAD_HEALTH << std::endl;
	}
	/*GetDAMAGE - get unit DAMAGE*/
	int GetDAMAGE(void) const {
		return DAMAGE;
	}
	/*GetTYPE_DAMAGE - get unit TYPE_DAMAGE*/
	int GetTYPE_DAMAGE(void) const {
		return TYPE_DAMAGE;
	}
	/*GetSPEED - get unit SPEED*/
	int GetSPEED(void) const {
		return SPEED;
	}
	/*GetHERO - get unit HERO*/
	Hero GetHERO(void) const {
		return HERO;
	}
	/*SetDAMAGE - set unit DAMAGE*/
	void SetDAMAGE(int damage) {
		DAMAGE = damage;
	}
	/*SetTYPE_DAMAGE - set uni TYPE_DAMAGE*/
	void SetTYPE_DAMAGE(int type_damage) {
		TYPE_DAMAGE = type_damage;
	}
	/*SetSPEED - set unit SPEED*/
	void SetSPEED(int speed) {
		SPEED = speed;
	}
	/*SetHERO - se unit HERO*/
	void SetSPEED(Hero hero) {
		HERO = hero;
	}
	/*Squad_Reinforcement - add people to the squad(Beginner - number of people)*/
	virtual void Squad_Reinforcement(int Beginner) {
		SetQUANTITY(GetQUANTITY() + Beginner);
		SetSQUAD_HEALTH(GetSQUAD_HEALTH() + Beginner * GetHEALTH());
	}
	/*Squad_Departed - delete people from squad(Departed_People - number of  deleted people)*/
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
	/*Military Destructor*/
	virtual ~Military() {
		std::cout << "Military died, in quantity " << GetQUANTITY() << std::endl;
	}
};
#endif