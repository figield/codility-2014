/*
Given an array A of N integers, we draw N discs in a 2D plane such that the I-th disc is centered on (0,I) and has a radius of A[I]. We say that the J-th disc and K-th disc intersect if J != K and J-th and K-th discs have at least one common point.
Write a function:
int solution(const vector<int> &A);
that, given an array A describing N discs as explained above, returns the number of pairs of intersecting discs. For example, given N=6 and:
A[0] = 1  A[1] = 5  A[2] = 2 
A[3] = 1  A[4] = 4  A[5] = 0  
intersecting discs appear in eleven pairs of elements:
0 and 1,
0 and 2,
0 and 4,
1 and 2,
1 and 3,
1 and 4,
1 and 5,
2 and 3,
2 and 4,
3 and 4,
4 and 5.
so the function should return 11.
The function should return −1 if the number of intersecting pairs exceeds 10,000,000.
Assume that:
N is an integer within the range [0..100,000];
each element of array A is an integer within the range [0..2147483647].
Complexity:
expected worst-case time complexity is O(N*log(N));
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

// Not my solution and it tooks me hours to understant this shit!  
int solution(const vector<int> &A) {
  int n = A.size();
  int result = 0;
  vector<long long> upperRanges, lowerRanges;
  for (long long i = 0; i < n; ++i){
    upperRanges.push_back(i + (long long)A[i]);
    lowerRanges.push_back(i - (long long)A[i]);
  }
  sort(upperRanges.begin(), upperRanges.end());
  sort(lowerRanges.begin(), lowerRanges.end());
  
  int j = 0, k = 0;
  while (j < n){
    while (k < n && upperRanges[j] >= lowerRanges[k]) k++;
    // the current disc is intersecting with itself, so we -1
    result += k - j -1;
    j++;
    if (result > 10000000) return -1;
  }
  return result;
}

/* 75%
int solution(const vector<int> &A){
  int N = A.size();
  int count = 0;
  
  for (int j=0;j<N-1;j++){
    for (int k=j+1;k<N;k++)
      if (j + A[j] - k + A[k] >= 0 ) count++;
    if(count > 10000000) return -1;
  }
  return count;
}
*/

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
