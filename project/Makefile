CC = g++
COV = -fprofile-arcs -ftest-coverage
DEBUG = -g
CFLAGS = -Wall  -std=c++11 -c -I. -lm
LFLAGS = -Wall -std=c++11 
OBJ = Helper.o Node.o KDTree.o 
# Default option
# builds the application and runs on given data. 
all: run

point.o:
	$(CC) $(CFLAGS) -c Helper.h

%.o: %.h
	$(CC) -c -o $@ $< $(CFLAGS)

#Targets for compiling 
build_kdtree: 
	$(CC) $(LFLAGS) $^  build_kdtree.cpp -o build_kdtree

query_kdtree: 
	$(CC) $(LFLAGS) $^  query_kdtree.cpp -o query_kdtree

compile: 
	$(CC) $(LFLAGS) $^  main.cpp

#To run given data set
run: build_kdtree query_kdtree
	./build_kdtree sample_data.csv out_tree.csv
	./query_kdtree query_data.csv out_tree.csv out_result.csv

#Runs the checker
run3: 
	./a.out

run1:
	./a.out data/sample_data_orig.csv data/query_data.csv

run2: build_kdtree query_kdtree
	./build_kdtree sample_data.csv
	./query_kdtree query_data.csv savetree.csv 

run4: build_kdtree query_kdtree
	./build_kdtree sample_set.csv out_tree.csv
	./query_kdtree query_set.csv out_tree.csv out_result.csv

run1:
	./a.out data/sample_data_orig.csv data/query_data.csv


#To run valgrind
valgrind:
	valgrind --leak-check=yes ./a.out data/sample_data_orig.csv data/query_data.csv 

#To clean
clear:
	rm *.o

clean:
	rm -rf *.dSYM *.o *.gcov *.gcno *.gcda build_kdtree query_kdtree
	rm -rf *.dSYM
