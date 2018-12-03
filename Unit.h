#ifndef __Unit_H__ 
#define __Unit_H__
#include <iostream>
#include <string>
class Unit {
protected:
    //Number of people in unit
    int QUANTITY;
    //Health of 1 person (no BUFF)
    int HEALTH_ONE;
    //Health of all squad (+BUFF)
    int SQUAD_HEALTH;
    //buff from HEROES
    int BUFF_HEALTH;
    //health of the last unit is left (there can not be more than hp at the top squad + buffs)
    int LEFT_HEALTH;
public:
    /*Unit Constructor(quantity - number of people;
     health - healthof 1 person)*/
    Unit(int left_heath, int quantity = 0, int health_one = 0,int buff_health = 0){
        QUANTITY = quantity;
        HEALTH_ONE = health_one;
        BUFF_HEALTH = buff_health;
        LEFT_HEALTH = left_heath;
        if (left_heath >= HEALTH_ONE+BUFF_HEALTH){
            printf("EROR LEFT_HEALTH");
        }
        if(QUANTITY >= 1){SQUAD_HEALTH = (QUANTITY-1) * (HEALTH_ONE+BUFF_HEALTH) + LEFT_HEALTH;}
        else{SQUAD_HEALTH = 0;}
    }
    /*GetHEALTHONE - get unit HEALTH*/
    int GetHEALTH_ONE(void) const {
        return HEALTH_ONE;
    }
    /*GetQUANTITY - get unit QUANTITY*/
    int GetQUANTITY(void) const {
        return QUANTITY;
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
    
    
    
    /*SetHEALTH_ONE - set unit HEALTH*/
    void SetHEALTH_ONE(int health_one) {
        HEALTH_ONE = health_one;
    }
    /*SetQUANTITY - set unit QUANTITY*/
    void SetQUANTITY(int quantity) {
        QUANTITY = quantity;
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
    
    
    //METHODS
    /*Squad_Reinforcement - add people to the squad(Beginner - number of people)*/
    virtual void Squad_Reinforcement(int Beginner) {
        QUANTITY = QUANTITY + Beginner;
        SQUAD_HEALTH = SQUAD_HEALTH + Beginner * HEALTH_ONE;
    }
    /*Squad_Departed - delete people from squad(Departed_People - number of  deleted people)*/
    virtual void Squad_Departed(int Departed_People) {
        if (Departed_People < QUANTITY) {
            QUANTITY = QUANTITY - Departed_People;
            SQUAD_HEALTH = SQUAD_HEALTH - Departed_People * HEALTH_ONE;
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
