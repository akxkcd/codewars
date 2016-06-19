CC = g++
DEBUG = -g
CFLAGS = -Wall -std=c++14 -c $(DEBUG) -I. -lm
LFLAGS = -Wall -std=c++14 $(DEBUG)
OBJ = Helper.o Node.o KDTree.o 
all: compile run

point.o:
	$(CC) $(CFLAGS) -c Helper.h

#Helper.o: 
#	$(CC) -c -o $@ Helper.h $(CFLAGS)

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
 
compile: $(OBJ)
	$(CC) $(LFLAGS) $^  main.cpp

run: 
	./a.out
run1:
	./a.out data/sample_data_orig.csv
clear:
	rm *.o

clean:
	rm *.o
