#include <stdio.h>
#include "spaceship.h"
#include "fuel.h"

void update_spaceship(spaceship *s)
{
  recalculate_fuel_consumption(s);

  if (s->burn_cycles > 0) {
    if (s->current_fuel_consumption > 0) {
      s->burn_cycles--;
      
      if (s->fuel - s->current_fuel_consumption <= 0) {
	s->fuel = 0;
	s->current_fuel_consumption = 0;
      } else {
	s->fuel -= s->current_fuel_consumption;
      }
    }
  }
}

void debug(const spaceship s)
{
  printf("Spaceship %s (mass: %d)\n", s.name, s.mass);
  printf("fuel   : %d   consumption: %d\n", s.fuel, s.current_fuel_consumption);
  printf("thrust : %d\n", s.current_thrust_level);
  printf("burn cycles: %d\n", s.burn_cycles);
}

void init_spaceship(spaceship *s, const char *name)
{
  s->name = name;
  s->mass = 1000;
  s->fuel = 0;
  s->max_fuel = 1000;
  s->fuel_efficiency = 34;
  s->current_thrust_level = 0;
  s->burn_cycles = 0;

  s->current_fuel_consumption = 0;
}
