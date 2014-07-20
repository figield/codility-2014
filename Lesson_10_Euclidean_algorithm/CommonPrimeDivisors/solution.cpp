/*
A prime is a positive integer X that has exactly two distinct divisors: 1 and X. The first few prime integers are 2, 3, 5, 7, 11 and 13.
A prime D is called a prime divisor of a positive integer P if there exists a positive integer K such that D * K = P. For example, 2 and 5 are prime divisors of 20.
You are given two positive integers N and M. The goal is to check whether the sets of prime divisors of integers N and M are exactly the same.
For example, given:
N = 15 and M = 75, the prime divisors are the same: {3, 5};
N = 10 and M = 30, the prime divisors aren't the same: {2, 5} is not equal to {2, 3, 5};
N = 9 and M = 5, the prime divisors aren't the same: {3} is not equal to {5}.
Write a function:

int solution(vector<int> &A, vector<int> &B);

that, given two non-empty zero-indexed arrays A and B of Z integers, returns the number of positions K for which the prime divisors of A[K] and B[K] are exactly the same.
For example, given:
    A[0] = 15   B[0] = 75
    A[1] = 10   B[1] = 30
    A[2] = 3    B[2] = 5
the function should return 1, because only one pair (15, 75) has the same set of prime divisors.
Assume that:
Z is an integer within the range [1..6,000];
each element of arrays A, B is an integer within the range [1..2147483647].
Complexity:
expected worst-case time complexity is O(Z*log(max(A)+max(B))2);
expected worst-case space complexity is O(1), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.

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

bool isCommon(int a, int b) {
  int gcdValue = gcd(a,b);
  //cout << "gcdValue:" << gcdValue << endl;
  int gcdA, gcdB;
  while(a!=1) {
    gcdA = gcd(a,gcdValue);
    //cout << "gcdA:" << gcdA << endl;
    //cout << "a:" << a << endl;
    if(gcdA==1)
      break;
    a = a/gcdA;
    //cout << "new a:" << a << endl;
  }
  if(a!=1)  
    return false;
 
  while(b!=1) {
    gcdB = gcd(b,gcdValue);
    //cout << "gcdB:" << gcdB << endl;
    //cout << "b:" << b << endl;
    if(gcdB==1)
      break;
    b = b/gcdB;
    //cout << "new b:" << b << endl;
  }
  return b==1;
}

int solution(vector<int> &A, vector<int> &B) {
  int res = 0;
  int Asize = A.size();
  for(int i=0;i<Asize;i++) 
    if(isCommon(A[i],B[i])) 
      res++;
  
  return res;
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

    vector<int> Q;
    getline(file, line);
    istringstream issQ(line);
    while (issQ >> i)
      Q.push_back(i);
    print_v(Q);   

    cout << "solution: " << solution(P, Q) << endl;
  
  }
  return 0;
}
