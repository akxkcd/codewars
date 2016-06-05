#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

void doBfs(vector<vector<int> > &inputMatrix, int row, int col, int countOfIslands) {
   queue<pair<int,int> > lastFound;
   int m = inputMatrix.size();
   int n = inputMatrix[0].size();

   lastFound.push(make_pair(row,col));
   while(lastFound.size() > 0) {
      pair<int,int> cur = lastFound.front();  
      lastFound.pop();  
      inputMatrix[cur.first][cur.second] = countOfIslands;
      if (cur.first+1 < m && inputMatrix[cur.first+1][cur.second] == 1) {
         lastFound.push(make_pair(cur.first+1,cur.second));
      }
      if (cur.first-1>=0 && inputMatrix[cur.first-1][cur.second] == 1) {
          lastFound.push(make_pair(cur.first-1,cur.second));
      }
      if (cur.second+1 < n && inputMatrix[cur.first][cur.second+1] == 1) {
         lastFound.push(make_pair(cur.first,cur.second+1));
      }
      if (cur.second-1 >= 0 && inputMatrix[cur.first][cur.second-1] == 1) {
         lastFound.push(make_pair(cur.first,cur.second-1));
      }
   }
}

/*
        0  2  0  3  0
        0  0  3  3  3
        4  0  0  3  0
        0  5  5  0  0
        6  0  5  0  7
*/
int countNumIslands(vector<vector<int> > &inputMatrix) {
   int m = inputMatrix.size();
   if (m == 0) {
      return 0;
   }
   int n = inputMatrix[0].size();
   int countOfIslands = 2;
   for (int i=0; i<m; i++) {
      for (int j=0; j<n; j++) {
         if (inputMatrix[i][j] == 1) {
            // Find and tag neighbors
            doBfs(inputMatrix, i, j, countOfIslands);
            countOfIslands++; // 7
         }
      }
   }
   return countOfIslands - 1;
}
int main() {
   vector<vector<int> > data;
   vector<int> row1;
   vector<int> row2;
   vector<int> row3;
   vector<int> row4;
   vector<int> row5;

   row1.push_back(0); row1.push_back(1); row1.push_back(0); row1.push_back(1); row1.push_back(0);
   row2.push_back(0); row2.push_back(0); row2.push_back(1); row2.push_back(1); row2.push_back(1);
   row3.push_back(1); row3.push_back(0); row3.push_back(0); row3.push_back(1); row3.push_back(0);
   row4.push_back(0); row4.push_back(1); row4.push_back(0); row4.push_back(0); row4.push_back(0);
   row5.push_back(1); row5.push_back(0); row5.push_back(1); row5.push_back(0); row5.push_back(1);
   data.push_back(row1);
   data.push_back(row2);
   data.push_back(row3);
   data.push_back(row4);
   data.push_back(row5);
   cout << countNumIslands(data) << endl;
   return 0;
}
