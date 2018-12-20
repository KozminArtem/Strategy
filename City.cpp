//
//  City.cpp
//  ПРОЕКТ
//
//  Created by Артем Козьмин on 20/12/2018.
//  Copyright © 2018 Артем Козьмин. All rights reserved.
//

#include "City.hpp"
#include <iostream>
#include <string>
#include <stdio.h>

City::City(Map Field, int X, int Y, int Size_city_map, std::string Name_city, std::string Player,std::vector<Unit> Civilian,std::vector<int> Resources,std::vector<Hero> Heroes_inside, Hero Policmen){
    FIELD = Field;
    POS = Field.Get_Tile(X, Y);
    SIZE_CITY_MAP = Size_city_map;
    NAME_CITY = Name_city;
    PLAYER = Player;
    CIVILIAN = Civilian;
    RESOURCES = Resources;
    HEROES_INSIDE = Heroes_inside;
    POLICMEN = Policmen;
}



   


