/*
A non-empty zero-indexed array A consisting of N integers is given. Array A represents numbers on a tape.
Any integer P, such that 0 < P < N, splits this tape into two non-empty parts: A[0], A[1], ..., A[P - 1] and A[P], A[P + 1], ..., A[N - 1].
The difference between the two parts is the value of: |(A[0] + A[1] + ... + A[P - 1]) - (A[P] + A[P + 1] + ... + A[N - 1])|
In other words, it is the absolute difference between the sum of the first part and the sum of the second part.
For example, consider array A such that:
  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
We can split this tape in four places:
P = 1, difference = |3 - 10| = 7 
P = 2, difference = |4 - 9| = 5 
P = 3, difference = |6 - 7| = 1 
P = 4, difference = |10 - 3| = 7 
Write a function:
int solution(vector<int> &A);
that, given a non-empty zero-indexed array A of N integers, returns the minimal difference that can be achieved.
For example, given:
  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
the function should return 1, as explained above.
Assume that:
N is an integer within the range [2..100,000];
each element of array A is an integer within the range [-1,000..1,000].
Complexity:
expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.
Copyright 2009¨C2014 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.

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
  if (n < 2) return 0;
  int sum_left = 0;
  int diff = 0;
  int min_diff = 0;
  int sum_all = 0;
  
  for (int i = 0; i < n; i++)  
    sum_all += A[i];
  sum_left = A[0];
  min_diff = abs(sum_all - sum_left - sum_left);  
  
  for (int i = 1; i < n-1; i++){  
    sum_left += A[i];
    diff = abs(sum_all - sum_left - sum_left);
    min_diff = min(min_diff, diff);
  }

  return min_diff;
}



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

