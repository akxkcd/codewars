#ifndef _HELPER_H_
#define _HELPER_H_
#include <vector>
#include <initializer_list>   
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
#include <ios>
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;
// Based class to contain each point given as an input. 
template <typename T = float>
class Point{
   vector<T> dimension;
   int point_index;
public:
   //default constructor
   Point() = default;
   
   //constructor with initializer_list   
   Point(const initializer_list<T>& input_list);

   Point(const vector<T>& vec,int index = 0);

   ~Point() = default;   

   T& operator[](const size_t index);
   const T& operator[](const size_t index) const;
   vector<T> getDimensionVector() const;
   int getIndex() const;
   void setIndex(int index) 
   {
      point_index=index;
   }
   T getDistance(const Point<T>& neighbor) const;
   void showPoint() const;
};

template <typename T>
Point<T>::Point(const initializer_list<T>& input_list): dimension(input_list){
}

template <typename T>
Point<T>::Point(const vector<T>& input_vec, int index):dimension(input_vec), point_index(index){
}

template <typename T>
T& Point<T>::operator[](const size_t index){
   return dimension[index];
}

template <typename T>
const T& Point<T>::operator[](const size_t index) const{
   return dimension[index];
}

template <typename T>
vector<T> Point<T>::getDimensionVector() const{
   return dimension;
}

template<typename T>
int Point<T>::getIndex() const{
   return point_index;
}

template<typename T>
void Point<T>::showPoint() const{
   for (int i=0; i<dimension.size(); i++) {
      cout << i << ":" << dimension[i] << endl;
   }
}

template<typename T>
T Point<T>::getDistance(const Point<T>& neighbor) const{
   vector<T> neighbor_dimension = neighbor.getDimensionVector();
   T cur_distance = 0;
   for(int i=0; i<dimension.size(); i++) {
      cur_distance += (dimension[i]-neighbor_dimension[i])*(dimension[i]-neighbor_dimension[i]);
   }
   cur_distance = sqrtf(cur_distance);
   return cur_distance;
}

// Class to handle IO. Specifically to read the input file used to generate the tree.
// This class has a static function readCSV to read the file. 
// This allows using this class without creating an object.  
template <typename T = float>
class IO_Points {
   IO_Points() = default;

public: 
   static vector<Point<T> > readCSV(const string& file_name) {
      ifstream in_file(file_name);
      vector<Point<T> > points;
      if (!in_file.good()) {
         cout << "could not open file in readCSV " << file_name << endl;
         throw 1;
         //throw "file could not open";
      }
      vector<T> in_points;
      string cur_line;
      int count = 0;
      while (!in_file.eof()) {
         getline(in_file, cur_line);
         if (cur_line.empty())
            continue;
         istringstream istream(cur_line);
         string cur_point;
         while (getline(istream, cur_point, ',')) {
            in_points.emplace_back(stof(cur_point));
         }
         points.emplace_back(in_points, count++);
         //points[count-1].showPoint();
         in_points.clear();
      } 
      return points;
   }
};

#endif
