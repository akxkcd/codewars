#include "Helper.h"
#include "Tester.h"
#include "KDTree.h"
//#include <utility> 
using namespace std;
// NOTE: This file is used to test all APIs
// build_kdtree.cpp and query_kdtree.cpp are the main functions
// which meet the requirements of this homework. 
int main(int argc, char *argv[]) {
	
   vector<Point<float> > points;
   vector<Point<float> > query_points;
   if (argc > 1) {
      points = IO_Points<float>::readCSV(string(argv[1]));
   }else { 
      points = IO_Points<float>::readCSV("data/sample_data.csv");
   }
   auto kdtree = KDTree<float>::make_kdtree(points);  
   kdtree.save_kdtree("savetree.csv"); 
   KDTree<float> saved_kdtree;
   saved_kdtree.read_kdtree("savetree.csv");
   saved_kdtree.save_kdtree("newtree.csv");
   if (argc > 2) {
      query_points = IO_Points<float>::readCSV(string(argv[2]));
   } else {
      query_points = IO_Points<float>::readCSV("data/query_data.csv");
   } 
   kdtree.query_kdtree(query_points);
   // This API tests the output of kdtree against brute force solution.  
   Tester<float>::test_kdtree(kdtree, points, query_points);
   points.clear();
   query_points.clear(); 
   return 0;
}


