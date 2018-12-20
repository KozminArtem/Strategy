#include "Unit.hpp"
Unit::Unit(int quantity) {
	QUANTITY = quantity;
}
int Unit::GetQUANTITY(void) const {
	return QUANTITY;
}
void Unit::SetQUANTITY(int quantity) {
	QUANTITY = quantity;
}
Unit::~Unit() {
}