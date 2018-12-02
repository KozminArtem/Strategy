#ifndef __Unit_H__ 
#define __Unit_H__
#include <iostream>
#include <string>
typedef int loc_t;
class Unit {
private:
	//    int id;
	loc_t HEROES;           //какому отряду принадлежат  0-никому 1-(1)герой  2-(2)герой
	std::string NAME;            //название отряда
	size_t DAMAGE;          //урон 1-го юнита
	size_t TYPE_DAMAGE;     //0-ближники 1- дальники
	size_t SPEED;           //скорость передвижения 1-го юнита
	size_t QUANTITY;        //количество юнитов в отряде
	size_t HEALTH;          //здоровье 1-го юнита
	size_t SQUAD_HEALTH;    //количество здоровья во всём отряде
public:
	Unit(loc_t heroes = 0, std::string name = "people", size_t damage = 0, size_t type_damage = 0, size_t speed = 0, size_t quantity = 0, size_t health = 0, size_t squad_health = 0) : HEROES(heroes), NAME(name), DAMAGE(damage), TYPE_DAMAGE(type_damage), SPEED(speed), QUANTITY(quantity), HEALTH(health), SQUAD_HEALTH(squad_health) {
		std::cout << "Created new unit: " << HEROES << ", ";
		if (NAME != "") {
			std::cout << NAME;
		}
		else { std::cout << "no NAME"; }
		std::cout << std::endl << "HEALTH 1 units:" << HEALTH << std::endl;
		std::cout << "DAMAGE 1 units:" << DAMAGE << std::endl;
		std::cout << "TYPE_DAMAGE 1 units:" << TYPE_DAMAGE << std::endl;
		std::cout << "SPEED 1 units:" << SPEED << std::endl;
		std::cout << "QUANTITY units:" << QUANTITY << std::endl;
		std::cout << "SQUAD_HEALTH units:" << SQUAD_HEALTH << std::endl;
	}


	//ВЗЯЛИ

	std::string GetNAME(void) const { return NAME; }
	size_t GetHEALTH(void) const { return HEALTH; }
	size_t GetDAMAGE(void) const { return DAMAGE; }
	size_t GetTYPE_DAMAGE(void) const { return TYPE_DAMAGE; }
	size_t GetSPEED(void) const { return SPEED; }
	size_t GetQUANTITY(void) const { return QUANTITY; }
	size_t GetSQUAD_HEALTH(void) const { return SQUAD_HEALTH; }
	loc_t GetHEROES(void) const { return HEROES; }

	//ПОЛОЖИЛИ
	std::string SetNAME(std::string str) {
		NAME = str;
		return NAME;
	}
	size_t SetHEALTH(size_t health) {
		HEALTH = health;
		return HEALTH;
	}
	size_t SetDAMAGE(size_t damage) {
		DAMAGE = damage;
		return DAMAGE;
	}
	size_t SetTYPE_DAMAGE(size_t type_damage) {
		TYPE_DAMAGE = type_damage;
		return TYPE_DAMAGE;
	}
	size_t SetSPEED(size_t speed) {
		SPEED = speed;
		return SPEED;
	}
	size_t SetQUANTITY(size_t quantity) {
		QUANTITY = quantity;
		return QUANTITY;
	}
	size_t SetSQUAD_HEALTH(size_t squad_health) {
		SQUAD_HEALTH = squad_health;
		return SQUAD_HEALTH;
	}


	//Поступило в отряд
	virtual size_t Squad_Reinforcement(size_t Beginner) {
		QUANTITY = QUANTITY + Beginner;
		SQUAD_HEALTH = SQUAD_HEALTH + Beginner * HEALTH;
		return QUANTITY;
	}
	//Ушло из отряда
	virtual size_t Squad_Departed(size_t Departed_People) {
		if (Departed_People < QUANTITY) {
			QUANTITY = QUANTITY - Departed_People;
			SQUAD_HEALTH = SQUAD_HEALTH - Departed_People * HEALTH;
		}
		else {
			QUANTITY = 0;
			SQUAD_HEALTH = 0;
		}
		return QUANTITY;
	}

	virtual ~Unit() {
		std::cout << NAME << " ,Units died, in quantity " << QUANTITY << std::endl << std::endl;
	}
};




//МИРНЫЕ ЖИТЕЛИ

class Civilians : public Unit {

public:
	Civilians(loc_t heroes = 0, std::string name = "Civilians", size_t damage = 0, size_t type_damage = 0, size_t speed = 0, size_t quantity = 0, size_t health = 0, size_t squad_health = 0) : Unit(heroes, name, damage, type_damage, speed, quantity, health, squad_health)
	{
			std::cout << "created new Civilians" << GetHEROES() << ", ";
			if (GetNAME() != "") {
				std::cout << GetNAME();
			}
			else { std::cout << "no NAME"; }
			std::cout << "HEALTH 1 units:" << GetHEALTH() << std::endl;
			std::cout << "DAMAGE 1 units:" << GetDAMAGE() << std::endl;
			std::cout << "TYPE_DAMAGE 1 units:" << GetTYPE_DAMAGE() << std::endl;
			std::cout << "SPEED 1 units:" << GetSPEED() << std::endl;
			std::cout << "QUANTITY units:" << GetQUANTITY() << std::endl;
			std::cout << "SQUAD_HEALTH units:" << GetSQUAD_HEALTH() << std::endl << std::endl;
	}



	virtual size_t Squad_Reinforcement(size_t Beginner) {
		SetQUANTITY(GetQUANTITY() + Beginner);
		SetSQUAD_HEALTH(GetSQUAD_HEALTH() + Beginner * GetHEALTH());
		return GetQUANTITY();
	}
	virtual size_t Squad_Departed(size_t Departed_People) {
		if (Departed_People < GetQUANTITY()) {
			SetQUANTITY(GetQUANTITY() - Departed_People);
			SetSQUAD_HEALTH(GetSQUAD_HEALTH() - Departed_People * GetHEALTH());
		}
		else {
			SetQUANTITY(0);
			SetSQUAD_HEALTH(0);
		}
		return GetQUANTITY();
	}


	virtual ~Civilians() {
		std::cout << GetNAME() << " ,Civilians died, in quantity " << GetQUANTITY() << std::endl << std::endl;
	}
};






//ВОЕННЫЕ



class Military : public Unit {

public:
	Military(loc_t heroes = 0, std::string name = "Military", size_t damage = 0, size_t type_damage = 0, size_t speed = 0, size_t quantity = 0, size_t health = 0, size_t squad_health = 0) : Unit(heroes, name, damage, type_damage, speed, quantity, health, squad_health)
	{
		std::cout << "created new Military: " << GetHEROES() << ", ";
		if (GetNAME() != "") {
			std::cout << GetNAME();
		}
		else { std::cout << "no NAME"; }
		std::cout << std::endl << "HEALTH 1 units:" << GetHEALTH() << std::endl;
		std::cout << "DAMAGE 1 units:" << GetDAMAGE() << std::endl;
		std::cout << "TYPE_DAMAGE 1 units:" << GetTYPE_DAMAGE() << std::endl;
		std::cout << "SPEED 1 units:" << GetSPEED() << std::endl;
		std::cout << "QUANTITY units:" << GetQUANTITY() << std::endl;
		std::cout << "SQUAD_HEALTH units:" << GetSQUAD_HEALTH() << std::endl << std::endl;
	}

	virtual size_t Squad_Reinforcement(size_t Beginner) {
		SetQUANTITY(GetQUANTITY() + Beginner);
		SetSQUAD_HEALTH(GetSQUAD_HEALTH() + Beginner * GetHEALTH());
		return GetQUANTITY();
	}
	virtual size_t Squad_Departed(size_t Departed_People) {
		if (Departed_People < GetQUANTITY()) {
			SetQUANTITY(GetQUANTITY() - Departed_People);
			SetSQUAD_HEALTH(GetSQUAD_HEALTH() - Departed_People * GetHEALTH());
		}
		else {
			SetQUANTITY(0);
			SetSQUAD_HEALTH(0);
		}
		return GetQUANTITY();
	}

	virtual ~Military() {
		std::cout << GetNAME() << " ,Military died, in quantity " << GetQUANTITY() << std::endl << std::endl;
	}
};
#endif

//loc_t HEROES;           //какому отряду принадлежат  0-нейтралы 1-(1)герой  2-(2)герой
//string NAME;            //название отряда
//size_t DAMAGE;          //урон 1-го юнита
//size_t TYPE_DAMAGE;     //0-ближники 1- дальники
//size_t SPEED;           //скорость передвижения 1-го юнита
//size_t QUANTITY;        //количество юнитов в отряде
//size_t HEALTH;          //здоровье 1-го юнита
//size_t SQUAD_HEALTH;    //количество здоровья во всём отряде