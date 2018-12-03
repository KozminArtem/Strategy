#ifndef __SAVE_H__
#define __SAVE_H__
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include "Map.h"
class Save {
private:
	//Save file
	std::fstream save_file;
	//Save location
	std::string save_location;
	//Name of the save file
	std::string save_name;
public:
	/*Save Constructor(save_name - name of the file where save is located;
	save_location - location where file is located(relative or absolute directory))*/
	Save(std::string save_name, std::string save_location = "");
	/*Save_Map - save map data on that save(Data - map that is going to be saved)*/
	void Save_Map(Map Data);
	/*Load_Map - load data from save as map array*/
	std::vector<std::vector<Tile>> Load_Map();
	/*Save_Delete - delete save file*/
	void Save_Delete();
	/*Save Destructor*/
	~Save();
};
#endif