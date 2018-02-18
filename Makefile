CC=gcc
CXX_FLAGS=-std=c99 -pedantic -Wall

spaceship: spaceship.o

.PHONY: clean
clean:
	$(RM) *.o *~ *.*~ spaceship
