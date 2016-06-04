
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct meetingInfo 
{
  int start;
  int end;
  meetingInfo(int a, int b): start(a), end(b) {};
};

bool compareMeetings(meetingInfo a, meetingInfo b) {
  return a.start<b.start;
}

int findMeetingRooms(vector<meetingInfo> meetings) {
  sort(meetings.begin(), meetings.end(), compareMeetings);
  int peak = 0;
  queue<meetingInfo> Q;
  Q.push(meetings[0]);
  for(int i=1; i<meetings.size(); i++) {
    while(!Q.empty() && Q.front().end < meetings[i].start) { Q.pop(); }
      Q.push(meetings[i]);
      peak = max(peak, (int)Q.size());
  }

  return peak;
  /*
  int result = 1;
  int maxRooms = 1;
  for (int i=1; i<meetings.size(); i++) {
    if (meetings[i].start >= meetings[i-1].start && meetings[i].start <= meetings[i-1].end) {
      result++;
    } else {
      result = 1;
    }
    maxRooms = max(maxRooms, result);
  }
  return maxRooms; */
}

int main() {
   meetingInfo a1(1,10);
   meetingInfo a2(12,14);
   meetingInfo a3(12,21);
   meetingInfo a4(1,2);
   meetingInfo a5(15,25);
   vector<meetingInfo> meetings;
   meetings.push_back(a1); 
   meetings.push_back(a2); 
   meetings.push_back(a3); 
   meetings.push_back(a4); 
   meetings.push_back(a5);
   cout << findMeetingRooms(meetings) << endl; 
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
