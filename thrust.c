#include "spaceship.h"
#include "thrust.h"

void prolong_burn_cycles(spaceship *s, unsigned int cycles)
{
  s->burn_cycles += cycles;
}

void increase_thrust(spaceship *s)
{
  if (s->current_thrust_level + 1 < 10) {
    s->current_thrust_level +=1;
  }
}

void decrease_thrust(spaceship *s)
{
  if (s->current_thrust_level - 1 >= 0) {
    s->current_thrust_level -=1;
  }
}
