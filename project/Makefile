CC = g++
DEBUG = -g
CFLAGS = -Wall -std=c++14 -c $(DEBUG)
LFLAGS = -Wall -std=c++14 $(DEBUG)

all: compile run

point.o:
	$(CC) $(CFLAGS) -c Helper.h
 
compile:
	$(CC) $(LFLAGS) main.cpp

run: 
	./a.out

