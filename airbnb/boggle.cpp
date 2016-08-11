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

void findBoggle(vector<vector<char> > &matrix, vector<vector<bool> > &visited, vector<string>&result, TrieNode *root, int i, int j, string cur_word) {
   if (root == NULL) return;
   if (root->children[matrix[i][j]-'a'] == NULL) return; 
   cout << "reached " << i << " " << j << endl;
   if (root->isLeaf ) {
      cout << "adding word:" << cur_word << endl;
	  result.push_back(cur_word);
   }
   visited[i][j] = true;
   int n = matrix.size();
   int m = matrix[0].size();
   for(int count=0; count<26; count++) {
      if(root->children[i] == NULL) continue;
	  char cur_letter = 'a' + count;
	  if(cur_letter == matrix[i][j]) {
	     for(int row=i-1; row<=i+1 && row<n;row++)
		    for(int col=j-1; col<=j+1 && col<m; col++)
			   if(row>=0 && col>=0 && !visited[row][col]) {
	   			  findBoggle(matrix,visited,result,root->children[i],row,col,cur_word+cur_letter);
			}
	  }
   }
   visited[i][j] = false;
}

int main() {
   vector<string> word_list = {"abc", "abd", "abcd", "adc"};
   vector<vector<char>> matrix = {{'a','b','c','d'},
                                  {'b','c','d','e'},
								  {'c','d','e','f'},
								  {'d','e','f','g'}};
   vector<string> result;
   vector<vector<bool> >visited(matrix.size(),vector<bool> (matrix[0].size(),false));
   Trie *trie = new Trie();

   for(auto words: word_list) {
      trie->add(words);
   }
   string cur_word = ""; 
   findBoggle(matrix,visited,result,trie->root,0,0,cur_word);
   for(auto words:result) {
      cout << words << endl;
   }
}


