/*
You are given N counters, initially set to 0, and you have two possible operations on them:
increase(X) − counter X is increased by 1,
max counter − all counters are set to the maximum value of any counter.
A non-empty zero-indexed array A of M integers is given. This array represents consecutive operations:
if A[K] = X, such that 1 ≤ X ≤ N, then operation K is increase(X),
if A[K] = N + 1 then operation K is max counter.
For example, given integer N = 5 and array A such that:
    A[0] = 3
    A[1] = 4
    A[2] = 4
    A[3] = 6
    A[4] = 1
    A[5] = 4
    A[6] = 4
the values of the counters after each consecutive operation will be:
    (0, 0, 1, 0, 0)
    (0, 0, 1, 1, 0)
    (0, 0, 1, 2, 0)
    (2, 2, 2, 2, 2)
    (3, 2, 2, 2, 2)
    (3, 2, 2, 3, 2)
    (3, 2, 2, 4, 2)
The goal is to calculate the value of every counter after all operations.
Write a function:
vector<int> solution(int N, vector<int> &A);
that, given an integer N and a non-empty zero-indexed array A consisting of M integers, returns a sequence of integers representing the values of the counters.
The sequence should be returned as:
a structure Results (in C), or
a vector of integers (in C++), or
a record Results (in Pascal), or
an array of integers (in any other programming language).
For example, given:
    A[0] = 3
    A[1] = 4
    A[2] = 4
    A[3] = 6
    A[4] = 1
    A[5] = 4
    A[6] = 4
the function should return [3, 2, 2, 4, 2], as explained above.
Assume that:
N and M are integers within the range [1..100,000];
each element of array A is an integer within the range [1..N + 1].
Complexity:
expected worst-case time complexity is O(N+M);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.
*/

#include <fstream>
#include <iostream>
#include <sstream> 
//-----------------------------------------------------------------------------------
#include <vector>
#include <stdlib.h>
using namespace std;

/* Result: 90%
vector<int> solution(int N, vector<int> &A){
  vector<int> counters(N, 0);
  int M = A.size();
  int max = 0;
  int prev_max = 0;
  for(int k=0;k<M;k++){
    if(A[k] <= N){ 
      ++counters[A[k]-1];
      if(counters[A[k]-1] > max) max = counters[A[k]-1];
    }
    else{
      if (prev_max<max){
        fill(counters.begin(), counters.end(), max);
        prev_max = max;
      }
    }
  }
  return counters;
}
*/

vector<int> solution(int N, vector<int> &A){
  vector<int> C(N, 0);
  int M = A.size();
  int min_value = 0;
  int max_value = 0;

  for(int K=0;K<M;K++){
    int X = A[K];
    
    if (X > N ) 
      min_value = max_value;
    else {

      if (C[X-1]<min_value) 
        C[X-1] = min_value+1;
      else C[X-1]++;

      max_value = max(max_value, C[X-1]);

    }
  }

  // make sure each element >= min_value
  for(int i = 0; i < N; ++i)
    if(C[i] < min_value) C[i] = min_value;

  return C;
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
    istringstream iss(line);
    int number;
    vector<int> A;
    while( iss >> number ) {
        A.push_back(number);
    }
    print_v(A);    
    vector<int> counters;
    counters = solution(5, A);
    print_v(counters); 
  }
  return 0;
}
