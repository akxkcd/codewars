#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
John,Smith,john.smith@gmail.com,Los Angeles,1
Jane,Roberts,janer@msn.com,"San Francisco, CA",0
"Alexandra ""Alex""",Menendez,alex.menendez@gmail.com,Miami,1
"""Alexandra Alex"""
John|Smith|john.smith@gmail.com|Los Angeles|1
Jane|Roberts|janer@msn.com|San Francisco, CA|0
Alexandra "Alex"|Menendez|alex.menendez@gmail.com|Miami|1
"Alexandra Alex"

Understand the problem:
For this problem, there are several cases need to consider:
1. For comma, transform to |
2. If comma is inside a quote, don't treat the comma as separated. Remove the comma and print the entire token. e.g. "San Francisco, CA" => San Francisco, CA
3. If there are double quotes, remove one. e.g. "Alexandra ""Alex""" => Alexandra "Alex". 
Note that """Alexandra Alex""" becomes "Alexandra Alex" because we first remove the outer-most quote, and then remove one quote of the double quote.
*/

vector<string> parseCSV(string inputString) {
   vector<string> result;
   if (inputString.size() == 0) {
      return result; 
   }

   bool inQuote = false;
   string str_buffer;
   for(int i=0; i<inputString.size(); i++) {
      if (inQuote) {
	     if(inputString[i] == '"') {
		    if (i == inputString.size()-1) {
			   result.push_back(str_buffer);
			   return result;
			} else if (inputString[i+1] == '"') {
			   str_buffer += inputString[i];
			   i++;
			} else {
			   result.push_back(str_buffer);
			   str_buffer = "";
			   inQuote = false;
			   i++;
			}
		 } else {
		    str_buffer += inputString[i];
		 }
	  } else {
	     if(inputString[i] == '"') {
		    inQuote = true;
		 } else if (inputString[i] == ',') {
			   result.push_back(str_buffer);
			   str_buffer = "";
		 } else {
		    str_buffer += inputString[i];
		 }
	  }
   }
   return result;
}

int main() {
/*
John,Smith,john.smith@gmail.com,Los Angeles,1
Jane,Roberts,janer@msn.com,"San Francisco, CA",0
"Alexandra ""Alex""",Menendez,alex.menendez@gmail.com,Miami,1
"""Alexandra Alex"""
John|Smith|john.smith@gmail.com|Los Angeles|1
Jane|Roberts|janer@msn.com|San Francisco, CA|0
Alexandra "Alex"|Menendez|alex.menendez@gmail.com|Miami|1
"Alexandra Alex"
*/   
   string input = "John,Smith,john.smith@gmail.com,Los Angeles,1";
   vector<string> result;

   result = parseCSV(input);
   cout << input << endl;
   for(auto word:result) {
      cout << " | " << word;
   }
   cout << endl;
   return 0;
}


