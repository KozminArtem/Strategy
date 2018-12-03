#ifndef __MILITARY_H__
#define __MILITARY_H__
#include "Unit.h"
#include "Hero.h"
#include "Map.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <random>
#include <time.h>
#include <stdlib.h>

class Military : public Unit{
protected:
    //Hero that have unit
    Hero HERO;
    
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
    
    //Map position
    Tile POS;
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
    Military( Hero hero, int quantity = 0, int health_one = 0, int left_health=0, int buff_health = 0, int damage_one = 0, int buff_damage = 0, int type_damage = 0, int devation_damage = 0, int travel_distance = 0, int buff_travel = 0, int left_travel = 0) :Unit(quantity){
        
        //HEROES
        HERO = hero;
        
        //DAMAGE
        DAMAGE_ONE = damage_one;
        TYPE_DAMAGE = type_damage;
        BUFF_DAMAGE = buff_damage;
        DEVATION_DAMAGE = devation_damage;
        SQUAD_DAMAGE = (DAMAGE_ONE+BUFF_DAMAGE)*QUANTITY;
        
        //HEALTH
        LEFT_HEALTH = left_health;
        BUFF_HEALTH = buff_health;
        HEALTH_ONE = health_one;
        if(QUANTITY >= 1){SQUAD_HEALTH = (QUANTITY-1) * (HEALTH_ONE+BUFF_HEALTH) + LEFT_HEALTH;}
        else{SQUAD_HEALTH = 0;}
        
        //TRAVEL
        TRAVEL_DISTANCE = travel_distance;
        BUFF_TRAVEL = buff_travel;
        LEFT_TRAVEL = left_travel;
        
        //POSITION
        POS = Tile(0, 0);
        
        
        
        
        std::cout << "Created new military unit."<<std::endl;
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
    
    
    
    
    /*  */
    /*                  */
    /*       GET        */
    /*                  */
    /*  */
    
    
    
    
    //HEROES
    /*GetHERO - get unit HERO*/
    Hero GetHERO(void) const {
        return HERO;
    }
    
    //DAMAGE
    /*GetDAMAGE - get 1 person DAMAGE(AVERAGE, no BUFF_DAMAGE)*/
    int GetDAMAGE_ONE(void) const {
        return DAMAGE_ONE;
    }
    /*GetTYPE_DAMAGE - get unit TYPE_DAMAGE*/
    int GetTYPE_DAMAGE(void) const {
        return TYPE_DAMAGE;
    }
    //Get BUFF DAMAGE of 1 person
    int GetBUFF_DAMAGE(void) const{
        return BUFF_DAMAGE;
    }
    //Get maximum deviation of damage from average (in percent)
    int GetDEVATION_DAMAGE(void) const{
        return DEVATION_DAMAGE;
    }
    //Get squad average damage on squad (+BUFF_DAMAGE)
    int GetSQUAD_DAMAGE(void) const{
        return SQUAD_DAMAGE;
    }
    
    //HEALTH
    /*GetHEALTHONE - get 1 person HEALTH(no BUFF)*/
    int GetHEALTH_ONE(void) const {
        return HEALTH_ONE;
    }
    //Get BUFF HEALTH
    int GetBUFF_HEALTH(void) const{
        return BUFF_HEALTH;
    }
    //Get health of the last unit is left (there can not be more than hp at the top squad + buffs)
    int GetLEFT_HEALTH(void) const{
        return LEFT_HEALTH;
    }
    /*GetSQUAD_HEALTH - get unit SQUAD_HEALTH(+BUFF)*/
    int GetSQUAD_HEALTH(void) const {
        return SQUAD_HEALTH;
    }
    
    //TRAVEL in map
    /*GetTRAVEL_DISTANCE - get unit SPEED(type - only size_t,no BUFF)*/
    int GetTRAVEL_DISTANCE(void) const {
        return TRAVEL_DISTANCE;
    }
    // Get BUFF travel distance
    int GetBUFF_TRAVEL(void) const{
        return BUFF_TRAVEL;
    }
    // Get travel distance left(+ BUFF)
    int GetLEFT_TRAVEL(void) const{
        return LEFT_TRAVEL;
    }
    
    //POSITION in map
    //Get position in map
    Tile GetPOS(void) const{
        return POS;
    }
    
    
    
    /*  */
    /*                  */
    /*        SET       */
    /*                  */
    /*  */
    
    
    
    
    //HEROES
    //Set unit in HEROES
    void SetHERO(Hero hero){
        HERO = hero;
    }
    
    //DAMAGE
    /*SetDAMAGE - Set 1 person DAMAGE(AVERAGE, no BUFF_DAMAGE)*/
    void SetDAMAGE_ONE(int damage_one){
        DAMAGE_ONE = damage_one;
    }
    /*SetTYPE_DAMAGE - set unit TYPE_DAMAGE*/
    void SetTYPE_DAMAGE(int type_damage){
        TYPE_DAMAGE = type_damage;
    }
    //Set BUFF DAMAGE of 1 person
    void SetBUFF_DAMAGE(int buff_damage){
        BUFF_DAMAGE = buff_damage;
    }
    //Set maximum deviation of damage from average (in percent)
    void SetDEVATION_DAMAGE(int devation_damage){
        DEVATION_DAMAGE = devation_damage;
    }
    //Set squad average damage on squad (+BUFF_DAMAGE)
    void SetSQUAD_DAMAGE(int squad_damage){
        SQUAD_DAMAGE = squad_damage;
    }
    
    //HEALTH
    /*SetHEALTHONE - set 1 person HEALTH(no BUFF)*/
    void SetHEALTH_ONE(int health_one){
        HEALTH_ONE = health_one;
    }
    //Set BUFF HEALTH
    void SetBUFF_HEALTH(int buff_health){
        BUFF_HEALTH = buff_health;
    }
    //Set health of the last unit is left (there can not be more than hp at the top squad + buffs)
    void SetLEFT_HEALTH(int left_health){
        LEFT_HEALTH = left_health;
    }
    /*SetSQUAD_HEALTH - set unit SQUAD_HEALTH(+BUFF)*/
    void SetSQUAD_HEALTH(int squad_health){
        SQUAD_HEALTH = squad_health;
    }
    
    //TRAVEL in map
    /*SetTRAVEL_DISTANCE - set unit SPEED(type - only size_t,no BUFF)*/
    void SetTRAVEL_DISTANCE(int travel_distance){
        TRAVEL_DISTANCE = travel_distance;
    }
    // Set BUFF travel distance
    void SetBUFF_TRAVEL(int buff_travel){
        BUFF_TRAVEL = buff_travel;
    }
    // Set travel distance left(+ BUFF)
    void SetLEFT_TRAVEL(int left_travel){
        LEFT_TRAVEL = left_travel;
    }
    
    //POSITION in map
    //Set position in map
    void SetPOS(Tile pos){
        POS = pos;
    }
    
    
    
    /*  */
    /*                  */
    /*     METHODS      */
    /*                  */
    /*  */
    
    
    
    
    /*Squad_Reinforcement - add people to the squad(Beginner - number of people)*/
    void Squad_Reinforcement(int Beginner) {
        SetQUANTITY(GetQUANTITY() + Beginner);
        SetSQUAD_HEALTH(GetSQUAD_HEALTH() + Beginner * (GetHEALTH_ONE()+GetBUFF_HEALTH()));
    }
    
    /*Squad_Departed - delete people from squad(Departed_People - number of  deleted people)*/
    void Squad_Departed(int Departed_People) {
        if (Departed_People < GetQUANTITY()) {
            SetQUANTITY(GetQUANTITY() - Departed_People);
            SetSQUAD_HEALTH(GetSQUAD_HEALTH() - Departed_People * (GetHEALTH_ONE()+GetBUFF_HEALTH()));
        }
        else {
            SetQUANTITY(0);
            SetSQUAD_HEALTH(0);
        }
    }
    
    //Attack_Damage - damage by unit
    int Attack_Damage(void){
        int Attack = 0;
        Attack = (GetDAMAGE_ONE() + GetBUFF_DAMAGE()) * GetQUANTITY();
        srand(time(NULL));
        float c = 0;
        for(int i = 0; i<3;i++){
            c = c + rand() % GetDEVATION_DAMAGE() - (float)GetDEVATION_DAMAGE() / 2;
        }
        if (c >= (float) GetDEVATION_DAMAGE() / 2){std::cout<<"Luck"<<std::endl;}
        if (c <= - (float) GetDEVATION_DAMAGE() / 2){std::cout<<"Fail"<<std::endl;}
        float Final_Damage = Attack + (float) (c/100) * Attack;
        return (int)Final_Damage;
    }
    
    
    
    
    
    /*Military Destructor*/
    virtual ~Military() {
        std::cout << "Military died, in quantity " << GetQUANTITY() << std::endl;
    }
};

#endif
