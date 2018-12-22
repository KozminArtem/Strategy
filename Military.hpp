#ifndef __MILITARY_H__
#define __MILITARY_H__
#include "Unit.hpp"
#include "Map.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include <random>
#include <time.h>
#include <stdlib.h>

class Military : public Unit{
protected:
    //Damage of one unit(NO BUFF_DAMAGE)
    int DAMAGE_ONE;
    //Damage distanse (1 - close-combat,2 - long range)
    int TYPE_DAMAGE;
    //damage on squad (+BUFF_DAMAGE)
    int SQUAD_DAMAGE;
    //BUFF DAMAGE
    int BUFF_DAMAGE;
    //maximum deviation of damage from average (in percent)
    int DEVATION_DAMAGE;
    
    
    //Health of 1 person (no BUFF)
    int HEALTH_ONE;
    //Health of all squad (+BUFF)
    int SQUAD_HEALTH;
    //buff from HEROES
    int BUFF_HEALTH;
    //health of the last unit is left (there can not be more than hp at the top squad + buffs)
    int LEFT_HEALTH;
    
    //max travel distance(no BUFF_TRAVEL)
    int TRAVEL_DISTANCE;
    // BUFF travel distance
    int BUFF_TRAVEL;
    // travel distance left(+ BUFF)
    int LEFT_TRAVEL;
public:
    /*Military Constructor(hero - hero that have unit;
     left_health - health of the last person is left(+BUFF_HEALTH);
     health_one - health of 1 person
     buff_health - buff_health one person;
     quantity - number of people;
     damage_one - one person damage(NO BUFF_DAMAGE);
     buff_damage - buff_damage
     type_damage - damage distanse;
     speed - unit speed;
     )*/
	Military(int quantity = 0, int health_one = 0, int left_health = 0, int buff_health = 0, int damage_one = 0, int buff_damage = 0, int type_damage = 0, int devation_damage = 0, int travel_distance = 0, int buff_travel = 0, int left_travel = 0);
    
    
    
    
                            /*  */
                    /*                  */
                    /*       GET        */
                    /*                  */
                            /*  */
    
    
    
    
    //DAMAGE
    /*GetDAMAGE - get 1 person DAMAGE(AVERAGE, no BUFF_DAMAGE)*/
	int GetDAMAGE_ONE(void) const;
    /*GetTYPE_DAMAGE - get unit TYPE_DAMAGE*/
	int GetTYPE_DAMAGE(void) const;
    //Get BUFF DAMAGE of 1 person
	int GetBUFF_DAMAGE(void) const;
    //Get maximum deviation of damage from average (in percent)
	int GetDEVATION_DAMAGE(void) const;
    //Get squad average damage on squad (+BUFF_DAMAGE)
	int GetSQUAD_DAMAGE(void) const;
    
    //HEALTH
    /*GetHEALTHONE - get 1 person HEALTH(no BUFF)*/
	int GetHEALTH_ONE(void) const;
    //Get BUFF HEALTH
	int GetBUFF_HEALTH(void) const;
    //Get health of the last unit is left (there can not be more than hp at the top squad + buffs)
	int GetLEFT_HEALTH(void) const;
    /*GetSQUAD_HEALTH - get unit SQUAD_HEALTH(+BUFF)*/
	int GetSQUAD_HEALTH(void) const;
    
    //TRAVEL in map
    /*GetTRAVEL_DISTANCE - get unit SPEED(type - only size_t,no BUFF)*/
	int GetTRAVEL_DISTANCE(void) const;
    // Get BUFF travel distance
	int GetBUFF_TRAVEL(void) const;
    // Get travel distance left(+ BUFF)
	int GetLEFT_TRAVEL(void) const;
    
    
    
                                /*  */
                        /*                  */
                        /*        SET       */
                        /*                  */
                                /*  */
    
    
    
    
    
    //DAMAGE
    /*SetDAMAGE - Set 1 person DAMAGE(AVERAGE, no BUFF_DAMAGE)*/
	void SetDAMAGE_ONE(int damage_one);
    /*SetTYPE_DAMAGE - set unit TYPE_DAMAGE*/
	void SetTYPE_DAMAGE(int type_damage);
    //Set BUFF DAMAGE of 1 person
	void SetBUFF_DAMAGE(int buff_damage);
    //Set maximum deviation of damage from average (in percent)
	void SetDEVATION_DAMAGE(int devation_damage);
    //Set squad average damage on squad (+BUFF_DAMAGE)
	void SetSQUAD_DAMAGE(int squad_damage);
    
    //HEALTH
    /*SetHEALTHONE - set 1 person HEALTH(no BUFF)*/
	void SetHEALTH_ONE(int health_one);
    //Set BUFF HEALTH
	void SetBUFF_HEALTH(int buff_health);
    //Set health of the last unit is left (there can not be more than hp at the top squad + buffs)
	void SetLEFT_HEALTH(int left_health);
    /*SetSQUAD_HEALTH - set unit SQUAD_HEALTH(+BUFF)*/
	void SetSQUAD_HEALTH(int squad_health);
    
    //TRAVEL in map
    /*SetTRAVEL_DISTANCE - set unit SPEED(type - only size_t,no BUFF)*/
	void SetTRAVEL_DISTANCE(int travel_distance);
    // Set BUFF travel distance
	void SetBUFF_TRAVEL(int buff_travel);
    // Set travel distance left(+ BUFF)
	void SetLEFT_TRAVEL(int left_travel);
    
    
    
                                /*  */
                        /*                  */
                        /*     METHODS      */
                        /*                  */
                                /*  */
    
    
    
    
    /*Squad_Reinforcement - add people to the squad(Beginner - number of people)*/
	void Squad_Reinforcement(int Beginner);
    
    /*Squad_Departed - delete people from squad(Departed_People - number of  deleted people)*/
	void Squad_Departed(int Departed_People);
    
    //Attack_Damage - damage by unit
	int Attack_Damage(void);
    //    take damage
	void Take_Damage(int Taken_Damage);
	/* Move_Mil - move military unit on 1 tile if that is possible (dir - direction to move;
	field - map, where unit moves)*/
    /*Military Destructor*/
	virtual ~Military();
};

#endif