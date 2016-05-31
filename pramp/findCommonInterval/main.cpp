
#include <iostream>
#include <vector>
using namespace std;

vector<int> findCommonTime(const vector<pair<int,int> > &timesA, const vector<pair<int,int> > &timesB, int dur) {
   vector<int> result;
   
   int pointerA = 0;
   int pointerB = 0;
   while(pointerA<timesA.size() && pointerB<timesB.size()) {
      int curEnd = min(timesA[pointerA].second, timesB[pointerB].second);
      int curStart = max(timesA[pointerA].first, timesB[pointerB].first);
      
      if (curEnd-curStart >= dur) {
         result.push_back(curStart);
         result.push_back(curEnd);
         return result;
      } else if (timesA[pointerA].first < timesB[pointerB].first) {
         pointerA++;
      } else {
         pointerB++;
      }
      
   }
   return result;
   
}

int main() {
   vector<pair<int, int> > timesA;
   vector<pair<int, int> > timesB;
   timesA.push_back(make_pair(5,7));
   timesA.push_back(make_pair(8,10));
   timesB.push_back(make_pair(5,6));
   timesB.push_back(make_pair(8,10));
   vector<int> res = findCommonTime(timesA, timesB, 1);
   cout << res[0] << " " << res[1] << endl;
   timesA.clear();
   timesB.clear();
   timesA.push_back(make_pair(7,8));
   timesA.push_back(make_pair(9,11));
   timesB.push_back(make_pair(5,6));
   timesB.push_back(make_pair(9,10));
   vector<int> res1 = findCommonTime(timesA, timesB, 1);
   cout << res1[0] << " " << res1[1] << endl;
   return 0;
}

// A: 5,9  8,10: m
// B: 5,7  9,10: n
// dur: 1hr
// 5-6
// A: 7,8  9,11
// B: 5,7  9,10
// dur: 1hr
// 9-10
