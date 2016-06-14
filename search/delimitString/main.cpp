#include <string.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <iterator>
#include <algorithm>
using namespace std;
/*
  This example is for tokenize a sentence. 
*/
int main()
{
  string input = "this had;- had try";
  char *str = new char[input.length()+1];
  strcpy(str,input.c_str());
  char *pch;
  pch = strtok(str, " ,.-");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, " ,.-");
  }


/*
string sentence = "And I feel fine...";
    istringstream iss(sentence);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         ostream_iterator<string>(cout, "\n"));
*/
}
