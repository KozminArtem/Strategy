#ifndef __RESOURCE_HPP__ 
#define __RESOURCE_HPP__
#include <vector>
#include <string>
class Resource{
private:
	// 1-food, 2-wood, 3-iron, 4-gold, 5-people
	std::vector<int> RESOURCE;
	//Names of resources
	static std::vector<std::string> NAME;
public:
	//Resource constructor
	Resource(int food = 0, int wood = 0, int iron = 0, int gold = 0, int people = 0);
	//Resource copy constructor
	Resource(const Resource& R);
	//Get_Resources - Get vector of resources as std vector
	std::vector<int> Get_Resources();
	//Set_Resources - Get vector of resources as std vector
	void Set_Resources(std::vector<int> R);
	//Food - Return value of food resources
	int Food();
	//Wood - Return value of wood resources
	int Wood();
	//Stone - Return value of stone resources
	int Iron();
	//Free_people - Return value of free people resources
	int Gold();
	//Busy_people - Return value of busy people resources
	int People();
	Resource operator+(Resource R);
	Resource operator=(const Resource& R);
	Resource operator=(const Resource&& R);
};
#endif