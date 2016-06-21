#include "Helper.h"
#include "Tester.h"
#include "KDTree.h"
using namespace std;

int main(int argc, char *argv[]) {
	
   vector<Point<float> > query_points;
 
   KDTree<float> saved_kdtree;
   if (argc > 1) {
      saved_kdtree.read_kdtree(string(argv[1]));
   } else { 
      saved_kdtree.read_kdtree("savetree.csv");
   }
   try {
      if (argc > 2) {
         query_points = IO_Points<float>::readCSV(string(argv[2]));
      } else {
         query_points = IO_Points<float>::readCSV("query_data.csv");
      } 
   } 
   catch(int n) {
      cout << "Error: could not open file" << endl;
      exit(0);
   }
   try {
      if (argc > 3) {
         saved_kdtree.query_kdtree(query_points, string(argv[3])); 
      } else {
         saved_kdtree.query_kdtree(query_points, "result.csv"); 
      }
   } 
   catch (int n) {
      cout << "Error: query_kdtree failed" << endl;
   }
   query_points.clear(); 
   return 0;
}


