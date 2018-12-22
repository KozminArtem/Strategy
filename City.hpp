#ifndef City_hpp
#define City_hpp
#include "Map.hpp"
#include "Unit.hpp"
#include "Hero.hpp"
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
    Map FIELD;
    int SIZE_CITY_MAP;
    std::string NAME_CITY;
    std::string PLAYER;
   // std::vector<building> BUILD;
    std::vector<Unit> CIVILIAN;
    //    resources: food tree rock busypeople freepeople
    std::vector<int> RESOURCES;
    std::vector<Hero> HEROES_INSIDE;
    Hero POLICMEN;
public:
    City(Map Field, int X, int Y, int Size_city_map, std::string Name_city, std::string Player, std::vector<Unit> Civilian,std::vector<int> Resources,std::vector<Hero> Heroes_inside,Hero Policmen);
    
    Tile GetPOS(void) const;
    int GetSIZE_CITY_MAP(void) const;
    std::string GetNAME_CITY(void) const;
    std::string GetPLAYER;
    //std::vector<building> GetBUILD(void) const;
    std::vector<Unit> GetCIVILIAN(void) const;
    std::vector<int> GetRESOURCES(void) const;
    std::vector<Hero> GetHEROES_INSIDE(void) const;
    Hero GetPOLICMEN(void) const;
    
    
    void SetSIZE_CITY_MAP(int size_city_map);
    void SetNAME_CITY(std::string name_city);
    void SetPLAYER(std::string player);
    //void GetBUILD(std::vector<building> build );
    void SetCIVILIAN(std::vector<Unit> civilian);
    void SetRESOURCES(std::vector<int> resources);
    void SetHEROES_INSIDE(std::vector<Hero> heroes_inside);
    void SetPOLICMEN(Hero policmen);
};
#endif /* Citi_hpp */
