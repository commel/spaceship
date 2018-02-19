#ifndef _SPACESHIP_H
#define _SPACESHIP_H

struct spaceship {
  const char *name;
  unsigned int burn_cycles;
  unsigned int mass;
  unsigned int fuel;
  unsigned int max_fuel;
  int current_thrust_level;
  unsigned int fuel_efficiency;
  unsigned int current_fuel_consumption; 
};

typedef struct spaceship spaceship;

void update_spaceship(spaceship *s);
void debug(const spaceship s);
void init_spaceship(spaceship *s, const char *name);

#endif
