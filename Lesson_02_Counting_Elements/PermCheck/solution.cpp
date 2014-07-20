/*
A non-empty zero-indexed array A consisting of N integers is given.
A permutation is a sequence containing each element from 1 to N once, and only once.
For example, array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2
is a permutation, but array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3
is not a permutation.
The goal is to check whether array A is a permutation.
Write a function:
int solution(vector<int> &A);
that, given a zero-indexed array A, returns 1 if array A is a permutation and 0 if it is not.
For example, given array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2
the function should return 1.
Given array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3
the function should return 0.
Assume that:
N is an integer within the range [1..100,000];
each element of array A is an integer within the range [1..1,000,000,000].
Complexity:
expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.
*/

#include <fstream>
#include <iostream>
// you can also use includes, for example:
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int solution(vector<int> &A) {
  int n = A.size();
  if (n < 1) return 1;
  vector<int> sorted(A);
  sort(sorted.begin(), sorted.end());
  int prev = 0;
  for (int i = 0; i < n; i++){ 
    if (sorted[i] - prev > 1) return 0;  
    else prev = sorted[i];
  }
  if (prev == n) return 1;
  return 0;
}

/*
int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    for (int i = 0; i < A.size(); ++i)
        if (A[i] != i+1) return 0;

    return 1;
}
*/

void print_v(vector<int> &A){
  int N = A.size();
  cout << "Size: " << N << endl;
  for(int i=0;i<N;i++){
    cout << A[i] << " ";
  }
  cout << endl;
}

void read_data(vector<int> &A, char *FileName){
  ifstream file;
  file.open(FileName);
  int i;
  while (file >> i)
    A.push_back(i);
}


int main(int argc,char *argv[]){
  if(argc < 2) {
    printf("You must provide at least one argument\n");
    exit(0);
  }
  vector<int> A; 
  read_data(A, argv[1]);
  print_v(A);
  int R = solution(A);
  cout  <<" The final result: "<< R << endl;
  return 0;
}

