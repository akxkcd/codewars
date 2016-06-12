#include <iostream>
#include <vector>
using namespace std;

int findFirstOccurence(const vector<int> &inputArray, int target) {
    int start = 0;
    int end = inputArray.size()-1;
    int result = -1;
    while(start<=end) {
        int mid = (start+end)/2;
        if (inputArray[mid] == target) {
            result = mid;
            end = mid-1;
        } else if (target < inputArray[mid]) {
            end = mid-1;
        } else {
            start = mid+1;
        }
    }
    return result;
}

int findLastOccurence(const vector<int> &inputArray, int target) {
    int start = 0;
    int end = inputArray.size()-1;
    int result = -1;
    while(start<=end) {
        int mid = (start+end)/2;
        if (inputArray[mid] == target) {
            result = mid;
            start = mid+1;
        } else if (target < inputArray[mid]) {
            end = mid-1;
        } else {
            start = mid+1;
        }
    }
    return result;
}

int findCount(const vector<int> &inputArray, int target) {
    int first = findFirstOccurence(inputArray, target);
    int last  = findLastOccurence(inputArray, target);
    cout << "Finding count for " << target << endl;
    if (first == -1) return 0;
    return (last - first + 1);
}

int main() {
  vector<int> inputArray;
  inputArray.push_back(5);
  inputArray.push_back(7);
  inputArray.push_back(7);
  inputArray.push_back(8);
  inputArray.push_back(8);
  inputArray.push_back(10);
  cout << findCount(inputArray, 7) << endl;
  cout << findCount(inputArray, 10) << endl;
  cout << findCount(inputArray, 11) << endl;
}
