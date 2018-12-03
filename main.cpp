#include "Map.h"
#include "Save.h"
#include "Unit.h"
#include "Military.h"
#include "Civilian.h"
#include "Hero.h"
int main() {
    //Save Save_1("Save_1", "Saved_Maps\\");
    Save Save_2("Save_2", "/Users/artemkozmin/Documents/ПРОЕКТ/ПРОЕКТ/Saved_maps/");
    //Save Save_3("Save_3", "Saved_Maps\\");
    //Map Test_Field_1(10, 20);
    Map Test_Field_2(Save_2.Load_Map());
    //Test_Field_1.Print();
    Test_Field_2.Print();
    /*Save_1.Save_Map(Test_Field_2);
     Save_3.Save_Map(Test_Field_1);
     Save Save_4("Save_4", "Saved_Maps\\");
     Save_4.Save_Delete();*/
    Hero Napoleon("Napoleon", Test_Field_2, 2, 3, "Dmitrii");
    //      Military( Hero hero, int left_health, int health_one = 0, int buff_health = 0, int quantity = 0, int damage_one = 0, int buff_damage = 0, int type_damage = 0, int speed = 0) :Unit(quantity)
    Unit *latnic = new Military(Napoleon, 12, 10, 3, 100,2,1,1,5);
    

    
    Napoleon.Print();
    Napoleon.Move(direction::down_right);
    Napoleon.Print();
    delete latnic;
    return 0;
}




