CC = g++
COV = -fprofile-arcs -ftest-coverage
DEBUG = -g
CFLAGS = -Wall -std=c++14 -c $(DEBUG) $(COV) -I. -lm
LFLAGS = -Wall -std=c++14 $(DEBUG) $(COV)
OBJ = Helper.o Node.o KDTree.o 
all: compile run

point.o:
	$(CC) $(CFLAGS) -c Helper.h

#Helper.o: 
#	$(CC) -c -o $@ Helper.h $(CFLAGS)

#%.o: %.cpp
#	$(CC) -c -o $@ $< $(CFLAGS)

%.o: %.h
	$(CC) -c -o $@ $< $(CFLAGS)
 
compile: $(OBJ)
	$(CC) $(LFLAGS) $^  main.cpp

run: 
	./a.out

run1:
	./a.out data/sample_data_orig.csv data/query_data.csv

valgrind:
	valgrind --leak-check=yes ./a.out data/sample_data_orig.csv data/query_data.csv 
clear:
	rm *.o

clean:
	rm *.o *.gcov *.gcno *.gcda
