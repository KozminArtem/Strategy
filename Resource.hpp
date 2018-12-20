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
		std::vector<int> res();
		res.push_back(food);
		res.push_back(wood);
		res.push_back(stone);
		res.push_back(free_people);
		res.push_back(busy_people);
		RESOURCE = res;
		std::vector<std::string> name();
		res.push_back("Food");
		res.push_back("Wood");
		res.push_back("Stone");
		res.push_back("Free_people");
		res.push_back("Busy_people");
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