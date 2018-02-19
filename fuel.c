#include "spaceship.h"
#include "fuel.h"

void recalculate_fuel_consumption(spaceship *s)
{
  if (s->burn_cycles > 0 && s->fuel > 0) {
    s->current_fuel_consumption = 1 * s->current_thrust_level;
  } else {
    s->current_fuel_consumption = 0;
  }
}

void increment_fuel(spaceship *s, int amount) {
  if (s->fuel + amount <= s->max_fuel)
    s->fuel += amount;
}
