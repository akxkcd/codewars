/*
Match regular expression: 
. : matches single character
* : matches 0 or any number of characters before it. 
e.g.
aaa matches a.a
aaa matches ab*ac*a
aaa does not match aa.a
aaa does not match ab*a
*/

#include <iostream>
using namespace std;

bool recursiveMatch(char *string, char *pattern) {
   if(*string == '\0' && *pattern == '\0') 
      return true;

   if(*string != '\0' && *pattern == '\0')
      return false;

   if (*(pattern+1) == '*') {
      if (*pattern == *string || (*pattern == '.' && string != '\0')) {
         return recursiveMatch(string+1, pattern+2) ||
                recursiveMatch(string, pattern+2) ||
                recursiveMatch(string+1, pattern);
      } else {
         return recursiveMatch(string, pattern+2);
      }
   }
   if(*string == *pattern || (*pattern == '.' && string != '\0')) {
      return recursiveMatch(string+1, pattern+1);
   }
   return false;
}

bool match(char *string, char *pattern) 
{
   if (string == NULL || pattern == NULL)
      return false;

   return recursiveMatch(string,pattern);
}

int main() {
   char string1[] = "aaa";
   char pattern1[] = "a.a";
   char pattern2[] = "ab*ac*a";
   char pattern3[] = "aa.a";
   char pattern4[] = "ab*a";

   if (match(string1, pattern1)) {
      cout << "matched" << endl;
   } else {
      cout << "did not match" << endl;
   }
   if (match(string1, pattern2)) {
      cout << "matched" << endl;
   } else {
      cout << "did not match" << endl;
   }
   if (match(string1, pattern3)) {
      cout << "matched" << endl;
   } else {
      cout << "did not match" << endl;
   }
   if (match(string1, pattern4)) {
      cout << "matched" << endl;
   } else {
      cout << "did not match" << endl;
   }
}
