#include "Helper.h"
#include "Tester.h"
#include "KDTree.h"
#include <utility> 
using namespace std;
///using std::pair;

int main(int argc, char *argv[]) {
	
   vector<Point<float> > points;
   vector<Point<float> > query_points;
   cout << argc << endl;
   if (argc > 1) {
      cout << argv[0] << " " << argv[1] << endl;
      points = IO_Points<float>::readCSV(string(argv[1]));
   }else { 
      points = IO_Points<float>::readCSV("data/sample_data.csv");
   }
   //KDTree<float> kdtree;// = new KDTree<float>();
   //kdtree = KDTree<float>::build_kdtree(points);
   auto kdtree = KDTree<float>::make_kdtree(points);   
   if (argc > 2) {
      query_points = IO_Points<float>::readCSV(string(argv[2]));
   } else {
      query_points = IO_Points<float>::readCSV("data/query_data.csv");
   } 
   //kdtree.query_kdtree(query_points[0]);  
   kdtree.query_kdtree(query_points); 
   Tester<float>::test_kdtree(kdtree, points, query_points);
   points.clear();
   query_points.clear(); 
   return 0;
}


