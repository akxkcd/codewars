#include "Helper.h"
#include "KDTree.h"
#include <utility> 
using namespace std;
///using std::pair;

int main(int argc, char **argv) {
	
   auto points = IO_Points<float>::readCSV(string("data/sample_data.csv"));
   //KDTree<float> kdtree;// = new KDTree<float>();
   //kdtree = KDTree<float>::build_kdtree(points);
   auto kdtree = KDTree<float>::make_kdtree(points);    
	//auto input_pts = Input_Interpreter<float>::readInputCSV(string("data/sample_data.csv"));
	return 0;
}
