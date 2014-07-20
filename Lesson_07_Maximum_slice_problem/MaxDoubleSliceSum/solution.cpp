/*
A non-empty zero-indexed array A consisting of N integers is given.
A triplet (X, Y, Z), such that 0 ≤ X < Y < Z < N, is called a double slice.
The sum of double slice (X, Y, Z) is the total of A[X + 1] + A[X + 2] + ... + A[Y − 1] + A[Y + 1] + A[Y + 2] + ... + A[Z − 1].
For example, array A such that:
    A[0] = 3
    A[1] = 2
    A[2] = 6
    A[3] = -1
    A[4] = 4
    A[5] = 5
    A[6] = -1
    A[7] = 2
contains the following example double slices:
double slice (0, 3, 6), sum is 2 + 6 + 4 + 5 = 17,
double slice (0, 3, 7), sum is 2 + 6 + 4 + 5 − 1 = 16,
double slice (3, 4, 5), sum is 0.
The goal is to find the maximal sum of any double slice.
Write a function:
int solution(vector<int> &A);
that, given a non-empty zero-indexed array A consisting of N integers, returns the maximal sum of any double slice.
For example, given:
    A[0] = 3
    A[1] = 2
    A[2] = 6
    A[3] = -1
    A[4] = 4
    A[5] = 5
    A[6] = -1
    A[7] = 2
the function should return 17, because no double slice of array A has a sum of greater than 17.
Assume that:
N is an integer within the range [3..100,000];
each element of array A is an integer within the range [−10,000..10,000].
Complexity:
expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.
*/


#include <fstream>
#include <iostream>
#include <sstream>
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
  
  int N = A.size();
  if (N <= 3) return 0;

  // Get the sum of maximum subarray, which ends at this position
  vector<int> sums_from_begining(N, 0);
  int max_sum_here = 0;
  for (int i=1; i<N-1; i++){
    max_sum_here = max(0, A[i] + max_sum_here);
    sums_from_begining[i] = max_sum_here;
  }
  //print_v(sums_from_begining);

  // Get the sum of maximum subarray, which begins this position
  // The same method, but we travel from the tail to the head
  vector<int> sums_from_end(N, 0);
  max_sum_here = 0;
  for (int i=N-2; i>0; i--){
    max_sum_here = max(0, A[i] + max_sum_here);
    sums_from_end[i] = max_sum_here;
  }
  //print_v(sums_from_end);

  int max_double_slice = 0;
  for(int i=0;i<N-2;i++)
    max_double_slice = max(max_double_slice, 
                           sums_from_begining[i] + sums_from_end[i+2]);
    
  return  max_double_slice;
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
