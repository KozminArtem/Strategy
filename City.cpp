#include "City.hpp"
#include <iostream>
#include <string>
#include <stdio.h>

City::City(Main_Map Field, int X, int Y, int Size_city_map, std::string Name_city, std::string Player, Hero Policmen, Resource Resources){
    FIELD = Field;
    POS = Field.Get_Tile(X, Y);
    SIZE_CITY_MAP = Size_city_map;
    NAME_CITY = Name_city;
    PLAYER = Player;
    CITY_RESOURCES = Resources;
    HEROES_INSIDE = std::vector<Hero*>();
    POLICMEN = Policmen;
}
void City::Add_Hero(Hero& hero) {
	HEROES_INSIDE.push_back(&hero);
}