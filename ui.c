#include <stdio.h>
#include <stdbool.h>
#include "thrust.h"
#include "fuel.h"
#include "ui.h"

void print_menu(int tick)
{
  printf("tick %d\n", tick);
  printf("1 - increment fuel by 10     2 - increment fuel by 100\n");
  printf("3 - increment thrust level   4 - decrement thrust level\n");
  printf("5 - burn for 1               6 - burn for 10\n");
  printf("9 - proceed\n");
  printf("0 - quit\n");
  
  printf("> ");
}

bool input(spaceship *s)
{
    int i;
    scanf("%d", &i);
    
    if (i == 1) {
      increment_fuel(s, 10);
    } else if (i == 2) {
      increment_fuel(s, 100);
    } else if (i == 3) {
      increase_thrust(s);
    } else if (i == 4) {
      decrease_thrust(s);
    } else if (i == 5) {
      prolong_burn_cycles(s, 1);
    } else if (i == 6) {
      prolong_burn_cycles(s, 10);
    } else if (i == 0) {
      return false;
    } else if (i == 9) {
      // nothing
      return true;
    }

    return true;
}
