/*
A non-empty zero-indexed array A consisting of N integers is given.
The leader of this array is the value that occurs in more than half of the elements of A.
An equi_leader is an index S such that 0 <= S < N - 1 and two sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N - 1] have leaders of the same value.
For example, given array A such that:
    A[0] = 4
    A[1] = 3
    A[2] = 4
    A[3] = 4
    A[4] = 4
    A[5] = 2
we can find two equi_leaders:
0, because sequences: (4) and (3, 4, 4, 4, 2) have the same leader, whose value is 4.
2, because sequences: (4, 3, 4) and (4, 4, 2) have the same leader, whose value is 4.
The goal is to count the number of equi_leaders. Write a function:
int solution(vector<int> &A);
that, given a non-empty zero-indexed array A consisting of N integers, returns the number of equi_leaders.
For example, given:
    A[0] = 4
    A[1] = 3
    A[2] = 4
    A[3] = 4
    A[4] = 4
    A[5] = 2
the function should return 2, as explained above.
Assume that:
N is an integer within the range [1..100,000];
each element of array A is an integer within the range [-1,000,000,000..1,000,000,000].
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
    int result = 0;
    
    vector<int> sorted(A);
    sort(sorted.begin(), sorted.end());
    int leader = sorted[n/2];
    int totalCount = 0;
    for (int i = 0; i < n; ++i)
        if (sorted[i] == leader){
            ++totalCount;
            if (sorted[i+1] != leader) break;
        }
    // the leader of the sub slices are the same as the main array
    // now we know the total count of the leader
    // we can simply decide if the number of first slice > s+1/2
    // and for the second slice, number > (n-s-1) / 2
    int count = 0;
    for (int s = 0; s < n-1; ++s){
        if (A[s] == leader) ++count;    
        if (count > (s+1)/2 && totalCount - count > (n-s-1)/2)
            ++result;
    }
    return result;
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
