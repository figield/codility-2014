/*
Write a function:

  int solution(const string &S);

that, given a string S, returns the index (counting from 0) of a character such that the part of the string to the left of that character is a reversal of the part of the string to its right. The function should return −1 if no such index exists.
Note: reversing an empty string (i.e. a string whose length is zero) gives an empty string.
For example, given a string:
"racecar"
the function should return 3, because the substring to the left of the character "e" at index 3 is "rac", and the one to the right is "car".
Given a string:
"x"
the function should return 0, because both substrings are empty.
Assume that:

 the length of S is within the range [0..2,000,000].

Complexity:

  expected worst-case time complexity is O(length(S));
  expected worst-case space complexity is O(1) (not counting the storage required for input arguments).

*/
 
#include <fstream>
#include <iostream>
#include <sstream> 
//-----------------------------------------------------------------------------------
#include <stdlib.h>
using namespace std;

// 92%, The task is not defined well
int solution(const string &S) {
  int size = S.size();
  if (size <= 1) return 0; // <- this should pass
  int res = 0;
  int half = (int)(size/2);
  //cout << "half: " << half << endl;
  if ((size % 2) == 0) return -1;
  for (int i = 0; i < half; i++){
    if (S[i] == S[size - 1 - i]) 
      res++;
    else 
      break; 
  }
  return res == half ? res : -1;
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
    cout << "Result:"<< solution(S) << endl << endl;
  }
  return 0;
}
