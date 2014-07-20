/*
Reverse the given string
*/

#include <fstream>
#include <iostream>
#include <sstream> 
//-----------------------------------------------------------------------------------
#include <vector>
#include <stack>
#include <algorithm>
#include <stdlib.h>
#include <string>
using namespace std;


#include <iostream>
#include <string>

using namespace std;

void reverseStr(string& x){
  string temp = "";
  int len = x.length();
  
  for(int i = len - 1; i >= 0; --i){
    temp += x[i];
    cout << "temp:" << temp << endl;
  }
  x = temp;
}



string solution(string &x) {    

  //string x = S;

  cout << "x = " << x << endl;

  reverse(x.begin(), x.end());

  cout << "x = " << x << endl;

  return x;
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
    //string S;
    //iss >> S;
    //cout << "Size:"<< S.size() << endl << S << endl;
    //string R = solution(S);
    //cout << "Result size:"<< R.size() << endl;
    //cout << "Result:" << R << endl;

    cout << "Size:"<< line.size() << endl << line << endl;
    string R2 = solution(line);
    cout << "Result2 size:"<< R2.size() << endl;
    cout << "Result2:" << R2 << endl;
    cout << "Oryginal:" << line << endl;
    reverseStr(line);
    cout << "after rverseSttr:" << line << endl;
  }
  return 0;
}
