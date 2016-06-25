#ifndef __TESTER_H__
#define __TESTER_H__
#include "Helper.h"
#include "KDTree.h"
// Class for testing the result against brute force solution. 
template<typename T>
class Tester {
public:
   static void test_kdtree(KDTree<T> &kdtree, vector<Point<T> > &input_points, vector<Point<T> > &query_points); 
   static void query_brute_force(vector<Point<T> > &input_points, Point<T> &query_point, T& min_distance, int &nearest_neightbor);
};

template<typename T>
void Tester<T>::test_kdtree(KDTree<T> &kdtree, vector<Point<T> > &input_points, vector<Point<T> > &query_points) {
   for(int i=0; i<query_points.size(); i++) {
      T kd_distance;
      int kd_nearest_neighbor;
      kdtree.query_kdtree(query_points[i], kd_distance, kd_nearest_neighbor);
      T min_distance;
      int brute_nearest_neighbor;
      query_brute_force(input_points, query_points[i], min_distance, brute_nearest_neighbor);
      if (kd_nearest_neighbor != brute_nearest_neighbor) {
         cout << "Error: found mismatch between kdtree: " << kd_nearest_neighbor << " vs brute-force search: " << brute_nearest_neighbor << endl;
      }
   }
     
}

template<typename T> 
void Tester<T>::query_brute_force(vector<Point<T> > &input_points, Point<T> &query_point, T& min_distance, int &nearest_neightbor) {
   min_distance = numeric_limits<T>::max();
   for(int i=0; i<input_points.size(); i++) {
      T nodeDistance = input_points[i].getDistance(query_point);
      if (nodeDistance < min_distance) {
         min_distance = nodeDistance;
         nearest_neightbor = input_points[i].getIndex();
      }
   } 
} 
#endif
