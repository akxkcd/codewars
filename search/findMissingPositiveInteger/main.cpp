#include <iostream>
#include <vector>
using namespace std;

int firstMissingPositive(vector<int> &inputArray) {
    
    int n = inputArray.size();
    for(int i = 0; i < n; ++ i)
        while(inputArray[i] > 0 && inputArray[i] <= n && inputArray[inputArray[i] - 1] != inputArray[i])
            swap(inputArray[i], inputArray[inputArray[i] - 1]);

    for(int i = 0; i < n; ++ i)
        if(inputArray[i] != i + 1)
            return i + 1;

    return n + 1;
    
}

int main() {
    vector<int> dataArray;
    dataArray.push_back(1);
    dataArray.push_back(2);
    dataArray.push_back(0);
    cout << firstMissingPositive(dataArray) << endl;
    dataArray.clear();
    dataArray.push_back(3);
    dataArray.push_back(4);
    dataArray.push_back(-1);
    dataArray.push_back(1);
    cout << firstMissingPositive(dataArray) << endl;
    dataArray.clear();
    dataArray.push_back(-8);
    dataArray.push_back(-7);
    dataArray.push_back(-6);
    cout << firstMissingPositive(dataArray) << endl;
    dataArray.clear();
}

