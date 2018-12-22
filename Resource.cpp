#include "Resource.hpp"
std::vector<std::string> Resource::NAME = { "Food","Wood","Stone","Free people","Busy people" };
Resource::Resource(int food, int wood, int stone, int free_people, int busy_people) {
	RESOURCE = std::vector<int>();
	RESOURCE.push_back(food);
	RESOURCE.push_back(wood);
	RESOURCE.push_back(stone);
	RESOURCE.push_back(free_people);
	RESOURCE.push_back(busy_people);
}
Resource::Resource(const Resource& R) {
	RESOURCE = R.RESOURCE;
}
std::vector<int> Resource::Get_Resources() {
	return RESOURCE;
}
void Resource::Set_Resources(std::vector<int> R) {
	RESOURCE = R;
}
int Resource::Food() {
	return RESOURCE[0];
}
int Resource::Wood() {
	return RESOURCE[1];
}
int Resource::Stone() {
	return RESOURCE[2];
}
int Resource::Free_people() {
	return RESOURCE[3];
}
int Resource::Busy_people() {
	return RESOURCE[4];
}
Resource Resource::operator+(Resource R) {
	Resource New;
	std::vector<int> new_res;
	for (int i = 0; i != RESOURCE.size(); i++) {
		new_res.push_back(RESOURCE[i] + R.RESOURCE[i]);
	}
	New.Set_Resources(new_res);
	return New;
}
Resource Resource::operator=(const Resource& R) {
	if (this == &R) return *this;
	else RESOURCE = R.RESOURCE;
}
Resource Resource::operator=(const Resource&& R) {
	if (this == &R) return *this;
	else RESOURCE = R.RESOURCE;
}