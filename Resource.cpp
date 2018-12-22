#include "Resource.hpp"
std::vector<std::string> Resource::NAME = { "Food","Wood","Iron","Gold","People"};
Resource::Resource(int food, int wood, int iron, int gold, int people) {
	RESOURCE = std::vector<int>();
	RESOURCE.push_back(food);
	RESOURCE.push_back(wood);
	RESOURCE.push_back(iron);
	RESOURCE.push_back(gold);
	RESOURCE.push_back(people);
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
int Resource::Iron() {
	return RESOURCE[2];
}
int Resource::Gold() {
	return RESOURCE[3];
}
int Resource::People() {
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