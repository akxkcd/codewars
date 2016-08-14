#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
Given a list of word and a target word, output all the words for each the edit distance with the target no greater than k.
*/
class TrieNode {
   public:
   bool isLeaf;
   vector<TrieNode*> children;
   TrieNode() {
      children.resize(26);
	  isLeaf = false;
//       for(int i=0; i<26; i++)
// 		 children[i] = new TrieNode();
   }   
};

class Trie {
   public:
   TrieNode *root;
   Trie() {
      root = new TrieNode();
   }

   void add(string s) {
      if (s.size() == 0) {
         return;
      }
      TrieNode *parent = root;
      for(int i=0; i<s.size(); i++) {
         char cur_char = s[i];
         if (parent->children[cur_char - 'a'] == NULL) {
            parent->children[cur_char - 'a'] = new TrieNode();
         }
         if (i == s.size()-1) {
            parent->children[cur_char - 'a']->isLeaf = true;
         } else {
//             parent->children[cur_char - 'a']->isLeaf = false;
         }
         parent = parent->children[cur_char - 'a'];
      }
   }
};

void getKEditDistanceRecusrive(string curr, string target, int k, TrieNode *root, vector<int> &prevDist, vector<string> &result ) {
   if(root->isLeaf) {
      if (prevDist[target.size()] <= k) {
	     result.push_back(curr);
	  } else {
	     return;
	  }
   }

   for(int i=0; i<26; i++) {
      if(root->children[i] == NULL) continue;

	  vector<int>currDist(target.size()+1);
      currDist[0] = curr.length()+1;
	  for(int j=1; j<prevDist.size(); j++) {
	     if(target[j-1] == char(i+'a')) {
		    currDist[j] = prevDist[j-1];
		 } else {
		    currDist[j] = min(min(prevDist[j-1], prevDist[j]), currDist[j-1]) + 1;
		 }
	  }
	  getKEditDistanceRecusrive(curr + char(i+'a'), target, k, root->children[i], currDist, result);
   }
}

vector<string> getKEditDistance(vector<string> &word_list, string target, int k) {
   vector<string> result;
   Trie *trie = new Trie();
   for(auto word:word_list) {
      trie->add(word);
   }
   vector<int> prevDist(target.size()+1);
   for(int i=0; i<prevDist.size(); i++)
      prevDist[i] = i;
   TrieNode *root = trie->root;
   getKEditDistanceRecusrive("", target, k, root, prevDist, result);
   return result;
}


int main() {
   vector<string> word_list = {"abc", "abd", "abcd", "adc"};
   string target = "ac";
   vector<string> result = getKEditDistance(word_list, target, 1);
   for(auto words: result) {
      cout << words << endl;
   }
}


