/*

*/

#include <fstream>
#include <iostream>
#include <sstream> 
//-----------------------------------------------------------------------------------
#include <stdlib.h>
#include <cmath>
using namespace std;


int solution(int K) {


  return 0;
}



//-----------------------------------------------------------------------------------

int main(int argc,char *argv[]){
  if(argc < 2) {
    printf("You must provide at least one argument\n");
    exit(0);
  }

  int max_pos = ~(1 << 31);
  int all_ones = -1;
  int max_neg = all_ones ^ max_pos;
  cout << "max_neg:" << max_neg << endl;
  cout << "max_pos:" << max_pos << endl;

  string line;
  ifstream file;
  file.open(argv[1]);  
  while(getline(file, line)){
    int K;
    istringstream issK(line);
    issK >> K;
    cout << K << endl;
    cout << "solution: " << solution(K) << endl;
    cout << endl;  
  }

  return 0;
}
