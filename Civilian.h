#ifndef __CIVILIAN_H__ 
#define __CIVILIAN_H__
#include "Unit.h"
class Civilian : public Unit{
public:
    /*Civilian Constructor(quantity - number of people;
     health - healthof 1 person)*/
    Civilian( int quantity = 0) : Unit(quantity)
    {
        std::cout << "Created new civilian unit." <<std::endl;
        std::cout << "QUANTITY of people:" << QUANTITY << std::endl;
    }
    
    /*Civilian Destructor*/
    virtual ~Civilian() {
        std::cout << "Civilians died, in quantity " << GetQUANTITY() << std::endl;
    }
};
#endif
