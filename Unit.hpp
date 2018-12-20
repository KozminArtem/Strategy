#ifndef __Unit_H__ 
#define __Unit_H__
#include <iostream>
#include <string>
class Unit {
protected:
    //Number of people in unit
    int QUANTITY;
public:
    /*Unit Constructor(quantity - number of people;)*/
	Unit(int quantity = 0);
    
    
    /*GetQUANTITY - get unit QUANTITY*/
	int GetQUANTITY(void) const;
    
    
    
    /*SetQUANTITY - set unit QUANTITY*/
	void SetQUANTITY(int quantity);
    
    
    /*Unit Destructor*/
	virtual ~Unit();
};
#endif
