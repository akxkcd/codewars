#ifndef _HELPER_H_
#define _HELPER_H_
#include <vector>
#include <initializer_list>   
#include <algorithm>
#include <numeric>
#include <fstream>
#include <string>
#include <sstream>
#include <ios>
#include <utility>
#include <iostream>
#include <math.h>

using namespace std;

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
   size_t getSize() const;
   size_t getIndex() const;
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

template <typename T>
size_t Point<T>::getSize() const{
   return dimension.size();
}

template<typename T>
size_t Point<T>::getIndex() const{
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
   /*transform(begin(pt1Feature), end(pt1Feature), begin(pt2Feature), begin(pt1Feature), []
      (vector<T>::iterator v1, vector<T>::iterator v2) {
      return (v1 - v2) * (v1 - v2);
   });*/

   cur_distance = sqrtf(cur_distance);
   return cur_distance;
}

template <typename T = float>
class IO_Points {
   IO_Points() = default;

public: 
   static vector<Point<T> > readCSV(const string& file_name) {
      ifstream in_file(file_name);
      vector<Point<T> > points;
      if (in_file.good()) {
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
      }
      return points;
   }
};

/*
// FIXME: cleanup
template <typename T = float>
class Input_Interpreter{
   Input_Interpreter() = default;
public:
   static vector<Point<T>> readInputCSV(const string& fname);
   static void writeToCSV(const string& fname, const vector<pair<int, T>>& result);
};

template <typename T>
vector<Point<T>> Input_Interpreter<T>::readInputCSV(const string& fname) {
   ifstream input_file(fname);
   vector<Point<T>> input_points;
   if (input_file.good()) { //if file is not good return empty list
      string line;
      vector<T> input_point;
      int i = 0;
      while (!input_file.eof()) {
         std::getline(input_file, line);
         if (line.empty())
            continue;
         std::istringstream line_stream(line);
         string token;
         while (std::getline(line_stream, token, ',')){
            input_point.push_back(std::stof(token));
         }
         input_points.emplace_back(input_point, i);
         ++i;
         input_point.clear();
      }
   }
   return input_points;
}

template<typename T>
void Input_Interpreter<T>::writeToCSV(const string & fname, const vector<pair<int, T>>& result){
   ofstream output_csv(fname.c_str(), std::ios::trunc);
   for (auto& pt : result) {
      output_csv << pt.first << "," << pt.second << "\n";
   }
}
*/

#endif
