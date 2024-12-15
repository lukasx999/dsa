CC=gcc
CFLAGS=-Wall -Wextra -ggdb -std=c99 -pedantic
DEPS=lib.h

all: main.o lib.o $(DEPS)
	$(CC) $(CFLAGS) $^ -o out

%.o: %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o out

.PHONY: clean
