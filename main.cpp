#include "Headers\Map.h"
#include "Headers\Save.h"
#include "Headers\Unit.h"
using namespace std;

int main() {
    Unit latnic = Military(1,"latnic",10,0,5,150,30,4500);
	Save Save_1("Save_1", "Saved_Maps\\");
	Save Save_2("Save_2", "Saved_Maps\\");
	Save Save_3("Save_3", "Saved_Maps\\");
	Map Test_Field_1(10, 20);
	Map Test_Field_2(Save_2.Load_Map());
	Test_Field_1.Print();
	Test_Field_2.Print();
	Save_1.Save_Map(Test_Field_2);
	Save_3.Save_Map(Test_Field_1);
	Save Save_4("Save_4", "Saved_Maps\\");
	Save_4.Save_Delete();
    return 0;
}



