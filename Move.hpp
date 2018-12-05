#ifndef __MOVE_HPP__ 
#define __MOVE_HPP__
#include "Map.h"
/* Move - move object on 1 tile if that is possible(dir - direction to move;
field - map, where you heed to move;
pos - object tile position;
move - object points of movement)*/
void Move(direction dir, Map field, Tile &pos, int &move);
#endif