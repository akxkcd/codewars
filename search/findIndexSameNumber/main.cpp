#include <iostream>
#include <vector>
using namespace std;

/*
Array Index & Element Equality
Given an array of sorted distinct integers named arr, write a function that returns an index i in arr for which arr[i] = i or -1 if no such index exists.
*/

int findIndexMatch(vector<int> & arr, int start, int end) {
   if (arr.size() == 0 || end<start) {
      return -1;
   }
   int mid = (start+end)/2;
   if (arr[mid] == mid) {
      return mid;
   } 
   if (start == end) {
      return -1;
   }
   
   if (arr[mid] < mid) {
      return findIndexMatch(arr, mid+1, end); // 2,3
   } else {
      return findIndexMatch(arr, start, mid-1);
   }
   
   return -1;
}

int main() {
   vector<int> arr;
   arr.push_back(-8);
   arr.push_back(0);
   arr.push_back(2);
   arr.push_back(5);
   cout << findIndexMatch(arr, 0, arr.size()-1) << endl;
   arr.clear();
   arr.push_back(-8);
   arr.push_back(0);
   arr.push_back(3);
   arr.push_back(5);
   cout << findIndexMatch(arr, 0, arr.size()-1) << endl;
}
