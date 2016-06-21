#include "Helper.h"
#include "Tester.h"
#include "KDTree.h"
using namespace std;

int main(int argc, char *argv[]) {
	
   vector<Point<float> > query_points;
 
   try {
      if (argc > 1) {
         query_points = IO_Points<float>::readCSV(string(argv[1]));
      } else {
         query_points = IO_Points<float>::readCSV("query_data.csv");
      } 
   } 
   catch(int n) {
      cout << "Error: could not open file" << endl;
      exit(0);
   }
   KDTree<float> saved_kdtree;
   try {
      if (argc > 2) {
         saved_kdtree.read_kdtree(string(argv[2]));
      } else { 
         saved_kdtree.read_kdtree("savetree.csv");
      }
   } 
   catch(int n) {
      cout << "Error: could not open file" << endl;
      exit(0);
   }
   try {
      if (argc > 3) {
         cout << "result will be present in:" << string(argv[3]) << endl;
         saved_kdtree.query_kdtree(query_points, string(argv[3])); 
      } else {
         cout << "result will be present in:" << "result.csv" << endl;
         saved_kdtree.query_kdtree(query_points, "result.csv"); 
      }
   } 
   catch (int n) {
      cout << "Error: query_kdtree failed" << endl;
   }
   query_points.clear(); 
   return 0;
}


