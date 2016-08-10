#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>


using namespace std;

#define abc pi

/*
You are given a list of words. Find if two words can be joined to form a palindrome. 
Expecting O(nk) solution where n = number of words and k is length. 

*/
bool checkPalindrome(const string& word) {
   int start = 0;
   int end = word.size()-1;
   while(start<end) {
      if (word[start++]!=word[end--]) return false;
   }
   return true;
}

struct cur_pairs {
   int first;
   int second;
};

vector<pair<int,int> > findPalindromes(const vector<string> words) {
   unordered_map<string, unordered_set <int>  > dictionary;
//    unordered_set < cur_pairs  > visitedPairs;
   // create dictionary of prefix
   for(int j=0; j<words.size(); j++) {
      string prefix;
	  string revPrefix;
	  string word = words[j];
	  prefix.reserve(word.size());
	  revPrefix.reserve(word.size());
	  for(int i=0; i<word.size(); i++) {
         prefix += word[i];
		 revPrefix = word[i] + revPrefix;
		 dictionary[prefix].insert(j);
		 dictionary[revPrefix].insert(j);
	  }
   }

   vector<pair<int,int> > result;
   for(int i=0; i<words.size(); i++) {
      string revWord(words[i]);
	  reverse(revWord.begin(), revWord.end());
      for(auto wordIndex:dictionary[revWord]) {
	     if (i == wordIndex) continue;
		 if(checkPalindrome(words[i]+words[wordIndex])) {
		    result.push_back(make_pair(i,wordIndex));
		 } 
		 else if(checkPalindrome(words[wordIndex]+words[i])) {
		    result.push_back(make_pair(wordIndex,i));
		 } 
	  }
   }
   return result;
}

int main() {
   vector<pair<int,int> > result;

   cout << "aba is palindrome:" << checkPalindrome("aba") << endl;
   cout << "abcd is palindrome:" << checkPalindrome("abcd") << endl;
   
   vector<string> words = {"bat", "tab", "tabaa", "aatab"};
   result = findPalindromes(words);
   for(auto cur:result) {
      cout << cur.first << " " << cur.second << endl;
   }
   return 0;
}


