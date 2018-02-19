#ifndef _FUEL_H
#define _FUEL_H

#include "spaceship.h"

void recalculate_fuel_consumption(spaceship *s);
void increment_fuel(spaceship *s, int amount);

#endif
