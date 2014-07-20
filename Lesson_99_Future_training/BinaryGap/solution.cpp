/*
A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.
For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary representation 1000010001) and contains two binary gaps: one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps.
Write a function:

int solution(int N);

that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.
For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5.
Assume that:

N is an integer within the range [1..2,147,483,647].

Complexity:

expected worst-case time complexity is O(log(N));
expected worst-case space complexity is O(1).
*/

#include <fstream>
#include <iostream>
#include <sstream> 
//-----------------------------------------------------------------------------------
#include <stdlib.h>
#include <cmath>
using namespace std;

// https://codility.com/demo/results/demoSWT9ZG-3NP/
int solution(int K) {
  int max0 = 0;
  int maxTemp = 0;
  int flag_1 = 0; 
  int range = (int)(log((long double) K) / log(2)) + 1; 
  //cout << "Range: " << range << endl;
  for (int i = range-1; i>=0; i--){
    if (K & 1){
      flag_1 = 1;
      //cout << (K & 1);
      max0 = max0 > maxTemp ? max0 : maxTemp;
      maxTemp = 0;
    } else {
      //cout << (K & 1);
      if (flag_1){
        maxTemp++;
        max0 = max0 > maxTemp ? max0 : maxTemp;
      }
    }
    K >>= 1;
  }
  //cout << endl;
  return max0;
}


int counting_zeros(int K) {
  unsigned int bits = K;
  if (K==0) return sizeof(K)*8;

  int max0 = 0;
  int maxTemp = 0;
  for (int i = sizeof(K) * 8-1; i>=0; i--){
    
    if (bits & 1){
      cout << (bits & 1);
      max0 = max0 > maxTemp ? max0 : maxTemp;
      maxTemp = 0;
    } else {
      cout << (bits & 1);
      maxTemp++;
      max0 = max0 > maxTemp ? max0 : maxTemp;
    }
    bits >>= 1;
  }

  cout << endl;
  return max0;
 
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
    cout << "Size of " << K << ": "<<sizeof(K)*8 << endl;
    cout << K <<" & 1 :"  << (K & 1) << endl;
    cout << "~" << K <<":"  << ~K << endl;
    cout << "solution: " << solution(K) << endl;
    cout << endl;  
  }

  return 0;
}
