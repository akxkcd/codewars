#include "Helper.h"
#include "Tester.h"
#include "KDTree.h"
using namespace std;

int main(int argc, char *argv[]) {
	
   vector<Point<float> > points;
   cout << argc << endl;
   if (argc > 1) {
      cout << argv[0] << " " << argv[1] << endl;
      points = IO_Points<float>::readCSV(string(argv[1]));
   } else { 
      points = IO_Points<float>::readCSV("sample_data.csv");
   }
   auto kdtree = KDTree<float>::make_kdtree(points); 
   if (argc > 2) {
      kdtree.save_kdtree(string(argv[2])); 
   } else {
      kdtree.save_kdtree("savetree.csv"); 
   } 
   points.clear();
   return 0;
}
