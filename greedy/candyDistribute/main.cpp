#include <iostream>
#include <vector>

using namespace std;

int candy(const vector<int> &ratings) {
     int size = ratings.size();   
     if(size<=1)
         return size;
     vector<int> num(size,1);
     for (int i = 1; i < size; i++)
     {
         if(ratings[i]>ratings[i-1])
             num[i]=num[i-1]+1;
     }
     for (int i= size-1; i>0 ; i--)
     {
         if(ratings[i-1]>ratings[i])
             num[i-1]=max(num[i]+1,num[i-1]);
     }
     int result=0;
     for (int i = 0; i < size; i++)
     {
         cout << i << " " << "score:" << ratings[i] << " candy:" << num[i] << endl;
         result+=num[i];
     }
     return result;
}

int main() {
  vector<int> rating;
  rating.push_back(1);
  rating.push_back(5);
  rating.push_back(2);
  rating.push_back(4);
  rating.push_back(3);
  cout << candy(rating) << endl;
}
