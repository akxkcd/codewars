#include <iostream>
#include <vector>
using namespace std;

int findMin(const vector<int> &inputSortedArray) {
    int start = 0;
    int end = inputSortedArray.size() - 1;
    int n = inputSortedArray.size();
    while (start<=end) {
        if (inputSortedArray[start]<=inputSortedArray[end]) return inputSortedArray[start];
        int mid = (start+end)/2;
        int next = (mid+1)%n, prev = (mid-1+n)%n;
        //cout << "start:" << start << " end:" << end << endl;
        //cout << "start:" << inputSortedArray[start] << " end:" << inputSortedArray[end] << endl;

        if (inputSortedArray[mid] <= inputSortedArray[next] && inputSortedArray[mid]<=inputSortedArray[prev]) return inputSortedArray[mid];
        else if (inputSortedArray[mid] <= inputSortedArray[end]) end = mid - 1;
        else if (inputSortedArray[mid] >= inputSortedArray[start]) start = mid+1;
    }
    return -1;
}

int main() {
  vector<int> inputArray;
  inputArray.push_back(15);
  inputArray.push_back(5);
  inputArray.push_back(6);
  inputArray.push_back(9);
  inputArray.push_back(11);
  inputArray.push_back(12);
  cout << findMin(inputArray) << endl;
}
