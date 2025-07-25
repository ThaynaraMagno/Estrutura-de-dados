CC=gcc
CFLAGS=-Wall -g

all: main

main: main.o lista.o
	$(CC) $(CFLAGS) -o main main.o lista.o

main.o: main.c lista.h
lista.o: lista.c lista.h

clean:
	rm -f *.o main
