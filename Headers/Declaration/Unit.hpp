#ifndef __Unit_HPP__ 
#define __Unit_HPP__
#include <iostream>
#include <string>
class Unit {
protected:
	//Number of people in unit
	int QUANTITY;
	//Health of 1 person
	int HEALTH;
	//Health of all squad
	int SQUAD_HEALTH;
public:
	/*Unit Constructor(quantity - number of people;
	health - healthof 1 person)*/
	Unit(int quantity = 0, int health = 0) {
		QUANTITY = quantity;
		HEALTH = health;
		SQUAD_HEALTH = QUANTITY * HEALTH;
	}
	/*GetHEALTH - get unit HEALTH*/
	int GetHEALTH(void) const {
		return HEALTH;
	}
	/*GetQUANTITY - get unit QUANTITY*/
	int GetQUANTITY(void) const {
		return QUANTITY;
	}
	/*GetSQUAD_HEALTH - get unit SQUAD_HEALTH*/
	int GetSQUAD_HEALTH(void) const {
		return SQUAD_HEALTH;
	}
	/*SetHEALTH - set unit HEALTH*/
	void SetHEALTH(int health) {
		HEALTH = health;
	}
	/*SetQUANTITY - set unit QUANTITY*/
	void SetQUANTITY(int quantity) {
		QUANTITY = quantity;
	}
	/*SetSQUAD_HEALTH - set unit SQUAD_HEALTH*/
	void SetSQUAD_HEALTH(int squad_health) {
		SQUAD_HEALTH = squad_health;
	}
	/*Squad_Reinforcement - add people to the squad(Beginner - number of people)*/
	virtual void Squad_Reinforcement(int Beginner) {
		QUANTITY = QUANTITY + Beginner;
		SQUAD_HEALTH = SQUAD_HEALTH + Beginner * HEALTH;
	}
	/*Squad_Departed - delete people from squad(Departed_People - number of  deleted people)*/
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
	/*Unit Destructor*/
	virtual ~Unit() {
	}
};
#endif