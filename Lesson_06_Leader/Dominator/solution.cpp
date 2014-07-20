/*
A zero-indexed array A consisting of N integers is given. The dominator of array A is the value that occurs in more than half of the elements of A.
For example, consider array A such that
A[0] = 3    A[1] = 4    A[2] =  3
A[3] = 2    A[4] = 3    A[5] = -1
A[6] = 3    A[7] = 3
The dominator of A is 3 because it occurs in 5 out of 8 elements of A (namely in those with indices 0, 2, 4, 6 and 7) and 5 is more than a half of 8.
Write a function
int solution(const vector<int> &A);
that, given a zero-indexed array A consisting of N integers, returns index of any element of array A in which the dominator of A occurs. The function should return -1 if array A does not have a dominator.
Assume that:
N is an integer within the range [0..100,000];
each element of array A is an integer within the range [-2,147,483,648..2,147,483,647].
For example, given array A such that
A[0] = 3    A[1] = 4    A[2] =  3
A[3] = 2    A[4] = 3    A[5] = -1
A[6] = 3    A[7] = 3
the function may return 0, 2, 4, 6 or 7, as explained above.
Complexity:
expected worst-case time complexity is O(N);
expected worst-case space complexity is O(1), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.
Copyright 2014 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/


#include <fstream>
#include <iostream>
// you can also use includes, for example:
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int find_dominator_value(vector<int> &A){
  int n = A.size();
  if (n <= 1) return n-1;
  vector<int> sorted(A);
  sort(sorted.begin(), sorted.end());
  int dominator = sorted[n/2];
  int totalCount = 0;
  for (int i = 0; i < n; ++i){
    if (sorted[i] == dominator) {
      ++totalCount;
      if (sorted[i+1] != dominator) break; 
    }
  }

  cout << "Dominator: " << dominator << endl;
  cout << "Occurance: " << totalCount << endl;

  if (totalCount > (int)n/2)
    return dominator;
  
  return -1; 
}

int find_dominator_index(vector<int> &A){
  int n = A.size();
  if (n <= 1) return n-1;
  vector<int> sorted(A);
  sort(sorted.begin(), sorted.end());
  int dominator = sorted[n/2];
  int totalCount = 0;
  int index = -1;
  for (int i = 0; i < n; ++i){
    if (A[i] == dominator) {
      ++totalCount;
      index = i; //any means any
    }
  }

  if (totalCount > (int)n/2) return index;
  return -1; 
}

int solution(vector<int> &A) {
   return find_dominator_index(A);
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

