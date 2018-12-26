#ifndef City_hpp
#define City_hpp
#include "Main_Map.hpp"
#include "Hero.hpp"
#include "Resource.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include <random>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
class City {
protected:
    Tile POS;
    Main_Map FIELD;
    int SIZE_CITY_MAP;
    std::string NAME_CITY;
    std::string PLAYER;
   // std::vector<building> BUILD;
    Resource CITY_RESOURCES;
    std::vector<Hero*> HEROES_INSIDE;
    Hero POLICMEN;
public:
    City(Main_Map Field, int X, int Y, int Size_city_map, std::string Name_city, std::string Player,Hero Policmen, Resource Resources = Resource(0, 0, 0, 0, 0));
    Tile GetPOS(void) const;
    int GetSIZE_CITY_MAP(void) const;
    std::string GetNAME_CITY(void) const;
    std::string GetPLAYER;
    //std::vector<building> GetBUILD(void) const;
    std::vector<Hero*> GetHEROES_INSIDE(void) const;
    Hero GetPOLICMEN(void) const;
    
    
    void SetSIZE_CITY_MAP(int size_city_map);
    void SetNAME_CITY(std::string name_city);
    void SetPLAYER(std::string player);
    //void GetBUILD(std::vector<building> build );
    void SetHEROES_INSIDE(std::vector<Hero*> heroes_inside);
    void SetPOLICMEN(Hero policmen);


	void Add_Hero(Hero& hero);
};
#endif /* City_hpp */
