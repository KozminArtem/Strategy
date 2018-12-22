#include "Map.hpp"
#include "Main_Map.hpp"
#include "Save.hpp"
#include "Unit.hpp"
#include "Military.hpp"
#include "Hero.hpp"
int main() {
    //Save Save_1("Save_1", "//Users/artemkozmin/Documents/опнейр/опнейр/Saved_Maps\\");
    Save Save_2("Save_2", "Saved_maps/"); ///Users/artemkozmin/Documents/опнейр/опнейр/
    //Save Save_3("Save_3", "Saved_Maps\\");
    //Map Test_Field_1(10, 20);
    Main_Map Test_Field_2(Save_2.Load_Map());
    //Test_Field_1.Print();
    Test_Field_2.Print();
    /*Save_1.Save_Map(Test_Field_2);
     Save_3.Save_Map(Test_Field_1);
     Save Save_4("Save_4", "Saved_Maps\\");
     Save_4.Save_Delete();*/
    Hero Napoleon("Napoleon", 2, 3, "Dmitrii");
	Test_Field_2.Add_Hero(Napoleon);
    //    Military( Hero hero, int quantity = 0, int health_one = 0, int left_health=0, int buff_health = 0, int damage_one = 0, int buff_damage = 0, int type_damage = 0, int devation_damage = 0, int travel_distance = 0, int buff_travel = 0, int left_travel = 0) :Unit(quantity){
    //
	Napoleon.add_Unit(Military(100, 10, 12, 2, 3, -1, 1, 20, 3, 2, 5));
	std::string c;
	direction dir;
	while (1 == 1){
		Napoleon.Print();
		Test_Field_2.Print();
		std::cin >> c;
		if (c == "w") dir = direction::up;
		if (c == "s") dir = direction::down;
		if (c == "a") dir = direction::left;
		if (c == "d") dir = direction::right;
		if (c == "q") dir = direction::up_left;
		if (c == "e") dir = direction::up_right;
		if (c == "z") dir = direction::down_left;
		if (c == "c") dir = direction::down_right;
		Test_Field_2.Move_Hero(Napoleon, dir);
	}
    Napoleon.Print();
    return 0;
}