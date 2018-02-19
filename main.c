#include <stdio.h>
#include <stdbool.h>
#include "spaceship.h"
#include "fuel.h"
#include "thrust.h"
#include "ui.h"

int main(int argc, char **argv)
{
  int tick = 0;
  bool running = true;
  spaceship s;

  init_spaceship(&s, "USS Enterprise");
  
  while(running) {
    tick++;
    debug(s);
    print_menu(tick);
    running = input(&s);
    update_spaceship(&s);
  }
  
  return 0;
}
