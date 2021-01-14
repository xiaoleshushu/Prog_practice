#Makefile files
OBJS = $(patsubst %.c, %.o, $(wildcard *.c))
CC = gcc
CFLAGS = -c -Wall -g
LFLAGS = -Wall

all: test
test: $(OBJS)
	$(CC) $(LFLAGS) $^ -o $@

clean:
	rm -rf *.o test

