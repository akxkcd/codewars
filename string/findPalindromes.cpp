#include <iostream>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
//#include <algorithm>
#include <utility>

using namespace std;

/*
Given a list of words. Find the words which can be joined together to form a palindrome. 
Consider a list: bat, cat, tab
bat and tab can be joined to form a palindrome. 
*/


template <>
  struct hash<string> {
    std::size_t operator()(const string & k) const {
      return std::hash<std::string>()(k.Data());
    };
  };
bool isPalindrome(const string& w){
	for (int i = 0; i < w.size(); i++){
		if (w[i] != w[w.size() - 1 - i])
			return false;
	}
	
	return true;
}


vector<pair<int, int> > findPalindrome(const vector<string>& words){
	unordered_map<string, unordered_set<int> > wordsMap;
	unordered_set< pair< int, int > > visitedPairs;

	// O( N * K ) where K is the length of the maximum word characters length in the vector
	for (int i = 0; i < words.size(); i++){
		string s;
		string revDirS;

		s.reserve(words[i].size());
		revDirS.reserve(words[i].size());

		for (int j = 0; j < words[i].size(); j++){
                        // ex. tabaa -> t , ta , tab , taba, tabaa
			s += words[i][j];

                        //ex. tabaa -> a , aa , baa , abaa , tabaa  
			revDirS = words[i][words[i].size() - 1 - j] + revDirS; 

			wordsMap[s].insert(i); // saving the indices rather than the words
			wordsMap[revDirS].insert(i);
		}
	}

	vector< pair<int, int> > ret;

	for (int i = 0; i < words.size(); i++){
		string revWord(words[i]);

		reverse(revWord.begin(), revWord.end());

		for (auto wordsIndex : wordsMap[revWord]){

			if (i == wordsIndex)
				continue; 

			int minIndex = min(i, wordsIndex);
			int maxIndex = max(i, wordsIndex);

			if (visitedPairs.count(make_pair(minIndex, maxIndex)) == 0){

				if (isPalindrome(words[i] + words[wordsIndex])){
					ret.push_back(make_pair(i, wordsIndex));
					visitedPairs.insert(make_pair(minIndex, maxIndex));

				}else if (isPalindrome(words[wordsIndex] + words[i])){
					ret.push_back(make_pair(wordsIndex,i));
					visitedPairs.insert(make_pair(minIndex, maxIndex));
				}
			}
		}
	}

	return ret;
}

int main() {
   
}
