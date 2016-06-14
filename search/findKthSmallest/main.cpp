#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> & nums, int left, int right) {
   int pivot = nums[left];
   int l = left+1;
   int r = right;
   while(l<=r) {
      if (nums[l] > pivot && nums[r] < pivot) {
         swap(nums[l++], nums[r++]);
      }
      if (nums[l] <= pivot) l++;
      if (nums[r] >= pivot) r--;
   }
   swap(nums[left], nums[r]);
   return r;
}

int findKthSmallest(vector<int> & nums, int k) {
   int left = 0;
   int right = nums.size() - 1;
   while(true) {
      int pos = partition(nums, left, right);
      cout << "pos:" << pos << endl;
      if (pos == k-1) return nums[pos];
      if (pos > k-1) right = pos - 1;
      else left = pos + 1;
   }
}

int main() {
   vector<int> inputArray;
   inputArray.push_back(3);
   inputArray.push_back(5);
   inputArray.push_back(2);
   inputArray.push_back(6);
   inputArray.push_back(1);
   inputArray.push_back(7);
   for (int i=0; i<inputArray.size(); i++) {
      cout << i << " : " << inputArray[i] << endl;
   }
   for (auto item : inputArray) {
      cout << item << endl;
   }
   cout << findKthSmallest(inputArray, 1) << endl;
   cout << findKthSmallest(inputArray, 2) << endl;
   cout << findKthSmallest(inputArray, 3) << endl;
   cout << findKthSmallest(inputArray, 4) << endl;
}
