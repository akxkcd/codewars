#include "iostream"
#include <vector>

using namespace std;

int findStringSimilarity(string inputString) {
    int count = inputString.size();
    for(int i=1; i<inputString.size(); i++) {
        int match = 0;
        for(int j=i; j<inputString.size(); j++) {
            if (inputString[j] == inputString[j-i]) {
                match++;
            } else break;
        }
        count += match;
        //cout << match << endl;
    }
    return count;
}
 
    /*
 * Complete the function below.
 */
vector < int > stringSimilarity(vector < string > inputs) {
    vector<int> result;
    for(auto cur_string: inputs) {
       int common = findStringSimilarity(cur_string);
       result.push_back(common);
       cout << "output: " << common << endl;
    }
    return result;


}

int main() {
   vector<string> inputs = {"ababaa"};
   stringSimilarity(inputs);
}
