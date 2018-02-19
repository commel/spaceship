#ifndef _THRUST_H
#define _THRUST_H

#include "spaceship.h"

void prolong_burn_cycles(spaceship *s, int unsigned cycles);

void increase_thrust(spaceship *s);
void decrease_thrust(spaceship *s);

#endif
