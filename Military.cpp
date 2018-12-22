#include "Military.hpp"
Military::Military(int quantity, int health_one, int left_health, int buff_health, int damage_one, int buff_damage, int type_damage, int devation_damage, int travel_distance, int buff_travel, int left_travel) :Unit(quantity) {

	//DAMAGE
	DAMAGE_ONE = damage_one;
	TYPE_DAMAGE = type_damage;
	BUFF_DAMAGE = buff_damage;
	DEVATION_DAMAGE = devation_damage;
	SQUAD_DAMAGE = (DAMAGE_ONE + BUFF_DAMAGE)*QUANTITY;

	//HEALTH
	LEFT_HEALTH = left_health;
	BUFF_HEALTH = buff_health;
	HEALTH_ONE = health_one;
	if (QUANTITY >= 1) { SQUAD_HEALTH = (QUANTITY - 1) * (HEALTH_ONE + BUFF_HEALTH) + LEFT_HEALTH; }
	else { SQUAD_HEALTH = 0; }

	//TRAVEL
	TRAVEL_DISTANCE = travel_distance;
	BUFF_TRAVEL = buff_travel;
	LEFT_TRAVEL = left_travel;



	std::cout << "Created new military unit." << std::endl;
	std::cout << "LEFT_HEALTH:" << LEFT_HEALTH << std::endl;
	std::cout << std::endl << "HEALTH of 1 person:" << HEALTH_ONE << std::endl;
	std::cout << "BUFF HEALTH of 1 person:" << BUFF_HEALTH << std::endl;
	std::cout << "QUANTITY of people:" << QUANTITY << std::endl;
	std::cout << "DAMAGE of 1 person:" << DAMAGE_ONE << std::endl;
	std::cout << "BUFF damage of 1 person:" << BUFF_DAMAGE << std::endl;
	std::cout << "TYPE_DAMAGE of unit:" << TYPE_DAMAGE << std::endl;
	std::cout << "TRAVEL_DISTANCE(NO BUFF):" << TRAVEL_DISTANCE << std::endl;
	std::cout << "SQUAD_HEALTH of unit:" << SQUAD_HEALTH << std::endl;
}
int Military::GetDAMAGE_ONE(void) const {
	return DAMAGE_ONE;
}
int Military::GetTYPE_DAMAGE(void) const {
	return TYPE_DAMAGE;
}
int Military::GetBUFF_DAMAGE(void) const {
	return BUFF_DAMAGE;
}
int Military::GetDEVATION_DAMAGE(void) const {
	return DEVATION_DAMAGE;
}
int Military::GetSQUAD_DAMAGE(void) const {
	return SQUAD_DAMAGE;
}
int Military::GetHEALTH_ONE(void) const {
	return HEALTH_ONE;
}
int Military::GetBUFF_HEALTH(void) const {
	return BUFF_HEALTH;
}
int Military::GetLEFT_HEALTH(void) const {
	return LEFT_HEALTH;
}
int Military::GetSQUAD_HEALTH(void) const {
	return SQUAD_HEALTH;
}
int Military::GetTRAVEL_DISTANCE(void) const {
	return TRAVEL_DISTANCE;
}
int Military::GetBUFF_TRAVEL(void) const {
	return BUFF_TRAVEL;
}
int Military::GetLEFT_TRAVEL(void) const {
	return LEFT_TRAVEL;
}
void Military::SetDAMAGE_ONE(int damage_one) {
	DAMAGE_ONE = damage_one;
}
void Military::SetTYPE_DAMAGE(int type_damage) {
	TYPE_DAMAGE = type_damage;
}
void Military::SetBUFF_DAMAGE(int buff_damage) {
	BUFF_DAMAGE = buff_damage;
}
void Military::SetDEVATION_DAMAGE(int devation_damage) {
	DEVATION_DAMAGE = devation_damage;
}
void Military::SetSQUAD_DAMAGE(int squad_damage) {
	SQUAD_DAMAGE = squad_damage;
}
void Military::SetHEALTH_ONE(int health_one) {
	HEALTH_ONE = health_one;
}
void Military::SetBUFF_HEALTH(int buff_health) {
	BUFF_HEALTH = buff_health;
}
void Military::SetLEFT_HEALTH(int left_health) {
	LEFT_HEALTH = left_health;
}
void Military::SetSQUAD_HEALTH(int squad_health) {
	SQUAD_HEALTH = squad_health;
}
void Military::SetTRAVEL_DISTANCE(int travel_distance) {
	TRAVEL_DISTANCE = travel_distance;
}
void Military::SetBUFF_TRAVEL(int buff_travel) {
	BUFF_TRAVEL = buff_travel;
}
void Military::SetLEFT_TRAVEL(int left_travel) {
	LEFT_TRAVEL = left_travel;
}
void Military::Squad_Reinforcement(int Beginner) {
	SetQUANTITY(GetQUANTITY() + Beginner);
	SetSQUAD_HEALTH(GetSQUAD_HEALTH() + Beginner * (GetHEALTH_ONE() + GetBUFF_HEALTH()));
}
void Military::Squad_Departed(int Departed_People) {
	if (Departed_People < GetQUANTITY()) {
		SetQUANTITY(GetQUANTITY() - Departed_People);
		SetSQUAD_HEALTH(GetSQUAD_HEALTH() - Departed_People * (GetHEALTH_ONE() + GetBUFF_HEALTH()));
	}
	else {
		SetQUANTITY(0);
		SetSQUAD_HEALTH(0);
	}
}
int Military::Attack_Damage(void) {
	int Attack = 0;
	Attack = (GetDAMAGE_ONE() + GetBUFF_DAMAGE()) * GetQUANTITY();
	srand(time(NULL));
	float c = 0;
	for (int i = 0; i < 3; i++) {
		c = c + rand() % GetDEVATION_DAMAGE() - (float)GetDEVATION_DAMAGE() / 2;
	}
	if (c >= (float)GetDEVATION_DAMAGE() / 2) { std::cout << "Luck" << std::endl; }
	if (c <= -(float)GetDEVATION_DAMAGE() / 2) { std::cout << "Fail" << std::endl; }
	float Final_Damage = Attack + (float)(c / 100) * Attack;
	return (int)Final_Damage;
}
void Military::Take_Damage(int Taken_Damage) {
	if (GetSQUAD_HEALTH() <= Taken_Damage) {
		SetQUANTITY(0);
		SetSQUAD_HEALTH(0);
		SetLEFT_HEALTH(0);
	}
	else {
		SetSQUAD_HEALTH(GetSQUAD_HEALTH() - Taken_Damage);
		int NEW_QUANTITY = 1 + (int)GetSQUAD_HEALTH() / (GetHEALTH_ONE() + GetBUFF_HEALTH());
		SetQUANTITY(NEW_QUANTITY);
		SetLEFT_HEALTH(GetSQUAD_HEALTH() - (GetQUANTITY() - 1)*(GetHEALTH_ONE() + GetBUFF_HEALTH()));
	}
}
Military::~Military() {
	std::cout << "Military died, in quantity " << GetQUANTITY() << std::endl;
}