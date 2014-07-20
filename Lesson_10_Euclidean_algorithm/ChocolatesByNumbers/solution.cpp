/*
Two positive integers N and M are given. Integer N represents the number of chocolates arranged in a circle, numbered from 0 to N   1.
You start to eat the chocolates. After eating a chocolate you leave only a wrapper.
You begin with eating chocolate number 0. Then you omit the next M   1 chocolates or wrappers on the circle, and eat the following one.
More precisely, if you ate chocolate number X, then you will next eat the chocolate with number (X + M) modulo N (remainder of division).
You stop eating when you encounter an empty wrapper.
For example, given integers N = 10 and M = 4. You will eat the following chocolates: 0, 4, 8, 2, 6.
The goal is to count the number of chocolates that you will eat, following the above rules.
Write a function:
int solution(int N, int M);
that, given two positive integers N and M, returns the number of chocolates that you will eat.
For example, given integers N = 10 and M = 4. the function should return 5, as explained above.
Assume that:
N and M are integers within the range [1..1,000,000,000].
Complexity:
expected worst-case time complexity is O(log(N+M));
expected worst-case space complexity is O(1).

*/

#include <fstream>
#include <iostream>
#include <sstream> 
//-----------------------------------------------------------------------------------
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int gcd(int a, int b) {
  if(a < b) return gcd(b, a);
  if(a % b == 0) return b;
  return gcd(b, a % b );
}

int solution(int N, int M) {
  if (M == 1) return N;
  return (int) N/gcd(M,N);
}

//-----------------------------------------------------------------------------------

void print_v(vector<int> &A){
  int N = A.size();
  cout << "Size: " << N << endl;
  for(int i=0;i<N;i++){
    cout << A[i] << " ";
  }
  cout << endl;
}

int main(int argc,char *argv[]){
  if(argc < 2) {
    printf("You must provide at least one argument\n");
    exit(0);
  }
  string line;
  ifstream file;
  file.open(argv[1]);  
  while(getline(file, line)){
    int i;
    vector<int> P;
    istringstream issP(line);
    while (issP >> i)
      P.push_back(i);
    print_v(P);   

    cout << "solution: " << solution(P[0], P[1]) << endl;
  
  }
  return 0;
}
