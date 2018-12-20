#ifndef __RESOURCE_HPP__ 
#define __RESOURCE_HPP__
#include <vector>
#include <string>
class Resource{
private:
	// 1-food, 2-wood, 3-stone, 4-free people, 5-busy people
	std::vector<int> RESOURCE;
	//
	static std::vector<std::string> NAME;
public:
	//Resource constructor
	Resource(int food, int wood, int stone, int free_people, int busy_people){
		RESOURCE = std::vector<int>();
		RESOURCE.push_back(food);
		RESOURCE.push_back(wood);
		RESOURCE.push_back(stone);
		RESOURCE.push_back(free_people);
		RESOURCE.push_back(busy_people);
		NAME = std::vector<std::string>();
		NAME.push_back("Food");
		NAME.push_back("Wood");
		NAME.push_back("Stone");
		NAME.push_back("Free_people");
		NAME.push_back("Busy_people");
	}
	int Food(){
		return RESOURCE[0];
	}
	int Wood(){
		return RESOURCE[1];
	}
	int Stone(){
		return RESOURCE[2];
	}
	int Free_people(){
		return RESOURCE[3];
	}
	int Busy_people(){
		return RESOURCE[4];
	}
};
#endif