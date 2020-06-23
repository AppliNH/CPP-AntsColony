#include "Food.h"

int Food::getSize() const { return size; }

void Food::grabFood() { size -= 1; }

