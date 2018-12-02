#include "Map.h"
#include "Save.h"
#include "Unit.h"
#include "Military.h"
#include "Civilian.h"
#include "Hero.h"
int main() {
    Unit *latnic = new Military(10,1,2,100,50);
	//Save Save_1("Save_1", "Saved_Maps\\");
	Save Save_2("Save_2", "Saved_Maps\\");
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
	Napoleon.Print();
	Napoleon.Move(direction::down_right);
	Napoleon.Print();
	delete latnic;
    return 0;
}



