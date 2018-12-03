#ifndef __MILITARY_H__
#define __MILITARY_H__
#include "Unit.h"
#include "Hero.h"
#include "Map.h"
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
    
    //Sequence of walking
    int INITIATIVE;
    //BUFF DAMAGE
    int BUFF_DAMAGE;
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
     initiative - sequense of walking;)*/
    Military( Hero hero, int left_health, int health_one = 0, int buff_health = 0, int quantity = 0, int damage_one = 0, int buff_damage = 0, int type_damage = 0, int speed = 0, int initiative=0) :Unit(left_health, quantity, health_one, buff_health){
        DAMAGE_ONE = damage_one;
        BUFF_DAMAGE = buff_damage;
        TYPE_DAMAGE = type_damage;
        SPEED = speed;
        HERO = hero;
        INITIATIVE = initiative;
        LEFT_HEALTH = left_health;
        BUFF_HEALTH = buff_health;
        pos = Tile(0, 0);
        SQUAD_DAMAGE = (DAMAGE_ONE+BUFF_DAMAGE)*QUANTITY;
        std::cout << "Created new military unit."<<std::endl;
        std::cout << "LEFT_HEALTH:" << LEFT_HEALTH << std::endl;
        std::cout << std::endl << "HEALTH of 1 person:" << HEALTH_ONE << std::endl;
        std::cout << "BUFF HEALTH of 1 person:" << BUFF_HEALTH << std::endl;
        std::cout << "QUANTITY of people:" << QUANTITY << std::endl;
        std::cout << "DAMAGE of 1 person:" << DAMAGE_ONE << std::endl;
        std::cout << "BUFF damage of 1 person:" << BUFF_DAMAGE << std::endl;
        std::cout << "TYPE_DAMAGE of unit:" << TYPE_DAMAGE << std::endl;
        std::cout << "SPEED of unit:" << SPEED << std::endl;
        std::cout << "INITIATIVE of unit:" << INITIATIVE << std::endl;
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
    //Get initiative unit
    int GetINITIATIVE(void) const{
        return INITIATIVE;
    }
    //Get BUFF DAMAGE of 1 person
    int GetBUFF_DAMAGE(void) const{
        return BUFF_DAMAGE;
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
    //    SetINITIATIVE - set unit INITIATIVE
    void SetINITIATIVE(int initiative){
        INITIATIVE = initiative;
    }
    //Set BUFF DAMAGE of 1 person
    void GetBUFF_DAMAGE(int buff_damage){
        BUFF_DAMAGE = buff_damage;
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
