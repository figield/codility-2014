/*
A zero-indexed array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.
Your goal is to find that missing element.
Write a function:
int solution(vector<int> &A);
that, given a zero-indexed array A, returns the value of the missing element.
For example, given array A such that:
  A[0] = 2
  A[1] = 3
  A[2] = 1
  A[3] = 5
the function should return 4, as it is the missing element.
Assume that:
N is an integer within the range [0..100,000];
the elements of A are all distinct;
each element of array A is an integer within the range [1..(N + 1)].
Complexity:
expected worst-case time complexity is O(N);
expected worst-case space complexity is O(1), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.
*/


#include <fstream>
#include <iostream>
// you can also use includes, for example:
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;


void print_v(vector<int> &A){
  int N = A.size();
  cout << "Size: " << N << endl;
  for(int i=0;i<N;i++){
    cout << A[i] << " ";
  }
  cout << endl;
}

int solution(vector<int> &A) {
  int n = A.size();
  if (n < 1) return 1;
  vector<int> sorted(A);
  sort(sorted.begin(), sorted.end());
  //print_v(sorted);
  int prev = 0;
  for (int i = 0; i < n; i++){
    //cout << "prev: " << prev << endl; 
    if (sorted[i] - prev > 1) return prev + 1;  
    else prev = sorted[i];
  }
  if (prev == n) return prev + 1;
  return -1;
  
}

/*
int solution(vector<int> &A) {
    long long sum = 0;
    long long N = A.size();
    for (long long i = 0; i< N; ++i)
        sum += A[i];
    
    // the missing element is the difference
    return (1 + N + 1)*(N+1)/2 - sum;
}
*/

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

