#include "Helper.h"
#include <utility> 
using namespace std;
///using std::pair;

int main(int argc, char **argv) {
	
	auto input_pts = IO_Points<float>::readCSV(string("data/sample_data.csv"));
	//auto input_pts = Input_Interpreter<float>::readInputCSV(string("data/sample_data.csv"));
	return 0;
}
