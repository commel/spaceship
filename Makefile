C_INCLUDE_PATH=src
CC=gcc
CFLAGS=-std=c99 -pedantic -Wall -Iinclude

spaceship: main.o spaceship.o thrust.o fuel.o ui.o

.PHONY: clean
clean:
	$(RM) *.o *~ *.*~ spaceship
