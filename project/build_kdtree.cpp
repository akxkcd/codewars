#include "Helper.h"
#include "Tester.h"
#include "KDTree.h"
using namespace std;

int main(int argc, char *argv[]) {
	
   vector<Point<float> > points;
   try {
      if (argc > 1) {
         points = IO_Points<float>::readCSV(string(argv[1]));
      } else { 
         points = IO_Points<float>::readCSV("sample_data.csv");
      }
   } 
   catch (int n) {
      cout << "Error: could not open file" << endl;
      exit(0);
   }
   auto kdtree = KDTree<float>::make_kdtree(points); 
   try {
      if (argc > 2) {
         kdtree.save_kdtree(string(argv[2])); 
      } else {
         kdtree.save_kdtree("savetree.csv"); 
      } 
   }
   catch (int n) {
      cout << "Error: could not open file" << endl;
      exit(0);
   }
   points.clear();
   return 0;
}
