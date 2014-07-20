/*
A string S consisting of N characters is considered to be properly nested if any of the following conditions is true:
S is empty;
S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string;
S has the form "VW" where V and W are properly nested strings.
For example, the string "{[()()]}" is properly nested but "([)()]" is not.
Write a function:
int solution(const string &S);
that, given a string S consisting of N characters, returns 1 if S is properly nested and 0 otherwise.
For example, given S = "{[()()]}", the function should return 1 and given S = "([)()]", the function should return 0, as explained above.
Assume that:
N is an integer within the range [0..200,000];
string S consists only of the following characters: "(", "{", "[", "]", "}" and/or ")".
Complexity:
expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N) (not counting the storage required for input arguments).
*/

#include <fstream>
#include <iostream>
#include <sstream> 
//-----------------------------------------------------------------------------------
#include <vector>
#include <stack>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int solution(const string &S) {    
  int size = S.size();
  if (size<1) return 1;
  if (size==1) return 0;

  stack<char> openBrackets;
  if (S[0] == ')' or S[0] == '}' or S[0] == ']' ) return 0;
  else openBrackets.push(S[0]);

  for (int i=1;i < size;i++)
    if(S[i] == '(' or S[i] == '{' or S[i] == '[' )
      openBrackets.push(S[i]);
    else {
      if (openBrackets.empty()) return 0;
      if ((S[i]==')' && openBrackets.top() =='(') ||
          (S[i]=='}' && openBrackets.top() =='{') ||
          (S[i]==']' && openBrackets.top() =='[')) 
        openBrackets.pop();
      else return 0;
    }
  return openBrackets.empty() ? 1 : 0;
}

int solution_on_vectors(const string &S) {    
  int size = S.size();
  if (size<1) return 1;
  if (size==1) return 0;
  vector<char> stack(size);
  if (S[0] == ')' or S[0] == '}' or S[0] == ']' ) return 0;
  else stack[0]=S[0];
  int ptr = 0;

  for (int i=1; i< S.size();i++){
    if(S[i] == '(' or S[i] == '{' or S[i] == '[' )
      stack[++ptr]=S[i];
    else if ((S[i]==')' && stack[ptr]=='(') ||
               (S[i]=='}' && stack[ptr]=='{') ||
               (S[i]==']' && stack[ptr]=='[')) 
      ptr--;
    else return 0;
  }
  return ptr == -1 ? 1 : 0;
}

//-----------------------------------------------------------------------------------

int main(int argc,char *argv[]){
  if(argc < 2) {
    printf("You must provide at least one argument\n");
    exit(0);
  }
  string line;
  ifstream file;
  file.open(argv[1]);  
  
  while(getline(file, line)){
    istringstream iss(line);
    string S;
    iss >> S;
    cout << "Size:"<< S.size() << endl << S << endl;
    cout << "Result:"<< solution(S) << endl;
  }
  return 0;
}
