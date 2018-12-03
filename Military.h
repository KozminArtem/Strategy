#ifndef __MILITARY_H__
#define __MILITARY_H__
#include "Unit.h"
#include "Hero.h"
#include "Map.h"
#include <iostream>
#include <stdio.h>
#include <string>
class Military : public Unit{
protected:
    //Hero that have unit
    Hero HERO;
    //Unit speed
    int SPEED;
    //Damage of one unit(NO BUFF_DAMAGE)
    int DAMAGE_ONE;
    //Damage distanse (1 - close-combat,2 - long range)
    int TYPE_DAMAGE;
    //damage on squad (+BUFF_DAMAGE)
    int SQUAD_DAMAGE;
    //Map position
    Tile pos;
    
    //BUFF DAMAGE
    int BUFF_DAMAGE;
    //Health of 1 person (no BUFF)
    int HEALTH_ONE;
    //Health of all squad (+BUFF)
    int SQUAD_HEALTH;
    //buff from HEROES
    int BUFF_HEALTH;
    //health of the last unit is left (there can not be more than hp at the top squad + buffs)
    int LEFT_HEALTH;
    
public:
    /*Military Constructor(hero - hero that have unit;
     left_health - health of the last person is left(+BUFF_HEALTH);
     health_one - healthof 1 person
     buff_health - buff_health one person;
     quantity - number of people;
     damage_one - one person damage(NO BUFF_DAMAGE);
     buff_damage - buff_damage
     type_damage - damage distanse;
     speed - unit speed;
     )*/
    Military( Hero hero, int left_health, int health_one = 0, int buff_health = 0, int quantity = 0, int damage_one = 0, int buff_damage = 0, int type_damage = 0, int speed = 0) :Unit(quantity){
        DAMAGE_ONE = damage_one;
        BUFF_DAMAGE = buff_damage;
        TYPE_DAMAGE = type_damage;
        SPEED = speed;
        HERO = hero;
        LEFT_HEALTH = left_health;
        BUFF_HEALTH = buff_health;
        pos = Tile(0, 0);
        HEALTH_ONE = health_one;
        SQUAD_DAMAGE = (DAMAGE_ONE+BUFF_DAMAGE)*QUANTITY;
        if (LEFT_HEALTH >= HEALTH_ONE + BUFF_HEALTH){
            printf("EROR LEFT_HEALTH");
        }
        if(QUANTITY >= 1){SQUAD_HEALTH = (QUANTITY-1) * (HEALTH_ONE+BUFF_HEALTH) + LEFT_HEALTH;}
        else{SQUAD_HEALTH = 0;}
        std::cout << "Created new military unit."<<std::endl;
        std::cout << "LEFT_HEALTH:" << LEFT_HEALTH << std::endl;
        std::cout << std::endl << "HEALTH of 1 person:" << HEALTH_ONE << std::endl;
        std::cout << "BUFF HEALTH of 1 person:" << BUFF_HEALTH << std::endl;
        std::cout << "QUANTITY of people:" << QUANTITY << std::endl;
        std::cout << "DAMAGE of 1 person:" << DAMAGE_ONE << std::endl;
        std::cout << "BUFF damage of 1 person:" << BUFF_DAMAGE << std::endl;
        std::cout << "TYPE_DAMAGE of unit:" << TYPE_DAMAGE << std::endl;
        std::cout << "SPEED of unit:" << SPEED << std::endl;
        std::cout << "SQUAD_HEALTH of unit:" << SQUAD_HEALTH << std::endl;
    }
    
    
    /*GetDAMAGE - get unit DAMAGE*/
    int GetDAMAGE_ONE(void) const {
        return DAMAGE_ONE;
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
    //Get BUFF DAMAGE of 1 person
    int GetBUFF_DAMAGE(void) const{
        return BUFF_DAMAGE;
    }
    /*GetHEALTHONE - get unit HEALTH*/
    int GetHEALTH_ONE(void) const {
        return HEALTH_ONE;
    }
    /*GetSQUAD_HEALTH - get unit SQUAD_HEALTH*/
    int GetSQUAD_HEALTH(void) const {
        return SQUAD_HEALTH;
    }
    //Get BUFF
    int GetBUFF(void) const{
        return BUFF_HEALTH;
    }
    //Get health of the last unit is left (there can not be more than hp at the top squad + buffs)
    int GetLEFT_HEALTH(void) const{
        return LEFT_HEALTH;
    }
    
    
    
    /*SetDAMAGE - set unit DAMAGE*/
    void SetDAMAGE_ONE(int damage_one) {
        DAMAGE_ONE = damage_one;
    }
    /*SetTYPE_DAMAGE - set unit TYPE_DAMAGE*/
    void SetTYPE_DAMAGE(int type_damage) {
        TYPE_DAMAGE = type_damage;
    }
    /*SetSPEED - set unit SPEED*/
    void SetSPEED(int speed) {
        SPEED = speed;
    }
    /*SetHERO - set unit HERO*/
    void SetSPEED(Hero hero) {
        HERO = hero;
    }
    //Set BUFF DAMAGE of 1 person
    void GetBUFF_DAMAGE(int buff_damage){
        BUFF_DAMAGE = buff_damage;
    }
    /*SetHEALTH_ONE - set unit HEALTH*/
    void SetHEALTH_ONE(int health_one) {
        HEALTH_ONE = health_one;
    }
    /*SetSQUAD_HEALTH - set unit SQUAD_HEALTH*/
    void SetSQUAD_HEALTH(int squad_health) {
        SQUAD_HEALTH = squad_health;
    }
    //Set BUFF
    void SetBUFF_HEALTH(int buff_health){
        BUFF_HEALTH = buff_health;
    }
    //Set health of the last unit is left (there can not be more than hp at the top squad + buffs)
    void SetLEFT_HEALTH(int left_health){
        LEFT_HEALTH = left_health;
    }
    
    
    
    
    
    /*Squad_Reinforcement - add people to the squad(Beginner - number of people)*/
    virtual void Squad_Reinforcement(int Beginner) {
        SetQUANTITY(GetQUANTITY() + Beginner);
        SetSQUAD_HEALTH(GetSQUAD_HEALTH() + Beginner * GetHEALTH_ONE());
    }
    /*Squad_Departed - delete people from squad(Departed_People - number of  deleted people)*/
    virtual void Squad_Departed(int Departed_People) {
        if (Departed_People < GetQUANTITY()) {
            SetQUANTITY(GetQUANTITY() - Departed_People);
            SetSQUAD_HEALTH(GetSQUAD_HEALTH() - Departed_People * GetHEALTH_ONE());
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
