/*
Write a function:
int solution(vector<int> &A);
that, given a non-empty zero-indexed array A of N integers, returns the minimal positive integer that does not occur in A.
For example, given:
  A[0] = 1    
  A[1] = 3    
  A[2] = 6
  A[3] = 4    
  A[4] = 1    
  A[5] = 2
the function should return 5.
Assume that:
N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
Complexity:
expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
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

int solution(vector<int> &A){
  int n = A.size();
  if (n < 1) return 1;
  sort(A.begin(), A.end());
  long prev = 0;
  for (int i = 0; i < n; i++){ 
    if ( A[i] > prev+1){ 
      return prev + 1;
    } else if (A[i]>0) prev = A[i];
  }
  if(prev == A[n-1]) return prev + 1;
  if(prev == 0) return 1;

  return 1;
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
    cout << solution(A) << endl;
  }
  return 0;
}
