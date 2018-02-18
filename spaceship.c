#include <stdio.h>

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

void prolong_burn_cycles(struct spaceship *s, unsigned int cycles)
{
  s->burn_cycles += cycles;
}

void recalculate_fuel_consumption(struct spaceship *s)
{
  if (s->burn_cycles > 0 && s->fuel > 0) {
    s->current_fuel_consumption = 1 * s->current_thrust_level;
  } else {
    s->current_fuel_consumption = 0;
  }
}



void update_spaceship(struct spaceship *s)
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

void increase_thrust(struct spaceship *s)
{
  if (s->current_thrust_level + 1 < 10) {
    s->current_thrust_level +=1;
  }
}

void decrease_thrust(struct spaceship *s)
{
  if (s->current_thrust_level - 1 >= 0) {
    s->current_thrust_level -=1;
  }
}

void increment_fuel(struct spaceship *s, int amount) {
  if (s->fuel + amount <= s->max_fuel)
    s->fuel += amount;
}

void debug(const struct spaceship s)
{
  printf("Spaceship %s (mass: %d)\n", s.name, s.mass);
  printf("fuel   : %d   consumption: %d\n", s.fuel, s.current_fuel_consumption);
  printf("thrust : %d\n", s.current_thrust_level);
  printf("burn cycles: %d\n", s.burn_cycles);
}

void init_spaceship(struct spaceship *s, const char *name)
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


int main(int argc, char **argv)
{
  int tick = 0;
  int running = 1;
  struct spaceship s;

  init_spaceship(&s, "USS Enterprise");
  
  while(running) {
    tick++;
    debug(s);
    printf("tick %d\n", tick);
    printf("1 - increment fuel by 10     2 - increment fuel by 100\n");
    printf("3 - increment thrust level   4 - decrement thrust level\n");
    printf("5 - burn for 1               6 - burn for 10\n");
    printf("9 - proceed\n");
    printf("0 - quit\n");
    
    printf("> ");
    
    update_spaceship(&s);

    int i;
    scanf("%d", &i);
    
    if (i == 1) {
      increment_fuel(&s, 10);
    } else if (i == 2) {
      increment_fuel(&s, 100);
    } else if (i == 3) {
      increase_thrust(&s);
    } else if (i == 4) {
      decrease_thrust(&s);
    } else if (i == 5) {
      prolong_burn_cycles(&s, 1);
    } else if (i == 6) {
      prolong_burn_cycles(&s, 10);
    } else if (i == 0) {
      running = 0;
    } else if (i == 9) {
      // nothing
      continue;
    }
  }
  
  return 0;
}
