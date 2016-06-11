#include <iostream>
#include <vector>
using namespace std;

/*
Rotated Sorted Array Search
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7  might become 4 5 6 7 0 1 2 ).
You are given a target value to search. If found in the array, return its index, otherwise return -1.
You may assume no duplicate exists in the array.
*/
int search(const vector<int> &rotatedArray, int target) {
    
    if (rotatedArray.size() == 0) {
        return -1;
    }
    
    int start = 0, end = rotatedArray.size()-1;
    
    while(end>=start) {
        int mid = (start + end)/2;
        //cout << start << " " << end << endl;
        if (rotatedArray[mid] == target) {
            return mid;
        } else if (start == end) {
            return -1;
        }
        else if (rotatedArray[mid] > rotatedArray[start]) {
            if (target >= rotatedArray[start] && target <= rotatedArray[mid]) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        } else {
            if (target >= rotatedArray[mid] && target <= rotatedArray[end]) {
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
    }
    return -1;
    
}

int main() {
   vector<int> arr;
   arr.push_back(7);
   arr.push_back(0);
   arr.push_back(2);
   arr.push_back(5);
   cout << search(arr, 0) << endl;
   arr.clear();
   arr.push_back(7);
   arr.push_back(0);
   arr.push_back(3);
   arr.push_back(5);
   cout << search(arr, 10) << endl;
}
