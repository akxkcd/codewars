CC = g++
#COV = -fprofile-arcs -ftest-coverage
DEBUG = -g
CFLAGS = -Wall -std=c++11 -c $(DEBUG) $(COV) -I. -lm
LFLAGS = -Wall -std=c++11 $(DEBUG) $(COV)
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

build_kdtree: $(OBJ)
	$(CC) $(LFLAGS) $^  build_kdtree.cpp -o build_kdtree

query_kdtree: $(OBJ)
	$(CC) $(LFLAGS) $^  query_kdtree.cpp -o query_kdtree

run: 
	./a.out

run1:
	./a.out data/sample_data_orig.csv data/query_data.csv

run2: build_kdtree query_kdtree
	./build_kdtree sample_data.csv
	./query_kdtree savetree.csv query_data.csv

run3: build_kdtree query_kdtree
	./build_kdtree sample_data_orig.csv out_tree.csv
	./query_kdtree out_tree.csv query_data.csv out_result.csv

valgrind:
	valgrind --leak-check=yes ./a.out data/sample_data_orig.csv data/query_data.csv 
clear:
	rm *.o

clean:
	rm *.o *.gcov *.gcno *.gcda
