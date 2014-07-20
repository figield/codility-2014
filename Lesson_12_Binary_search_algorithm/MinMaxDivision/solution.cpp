/*
You are given integers K, M and a non-empty zero-indexed array A consisting of N integers. Every element of the array is not greater than M.
You should divide this array into K blocks of consecutive elements. The size of the block is any integer between 0 and N. Every element of the array should belong to some block.
The sum of the block from X to Y equals A[X] + A[X + 1] + ... + A[Y]. The sum of empty block equals 0.
The large sum is the maximal sum of any block.
For example, you are given integers K = 3, M = 5 and array A such that:
  A[0] = 2
  A[1] = 1
  A[2] = 5
  A[3] = 1
  A[4] = 2
  A[5] = 2
  A[6] = 2
The array can be divided, for example, into the following blocks:
[2, 1, 5, 1, 2, 2, 2], [], [] with a large sum of 15;
[2], [1, 5, 1, 2], [2, 2] with a large sum of 9;
[2, 1, 5], [], [1, 2, 2, 2] with a large sum of 8;
[2, 1], [5, 1], [2, 2, 2] with a large sum of 6.
The goal is to minimize the large sum. In the above example, 6 is the minimal large sum.
Write a function:
int solution(int K, int M, vector<int> &A);
that, given integers K, M and a non-empty zero-indexed array A consisting of N integers, returns the minimal large sum.
For example, given K = 3, M = 5 and array A such that:
  A[0] = 2
  A[1] = 1
  A[2] = 5
  A[3] = 1
  A[4] = 2
  A[5] = 2
  A[6] = 2
the function should return 6, as explained above. Assume that:
N and K are integers within the range [1..100,000];
M is an integer within the range [0..10,000];
each element of array A is an integer within the range [0..M].
Complexity:
expected worst-case time complexity is O(N*log(N+M));
expected worst-case space complexity is O(1), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.
*/

#include <fstream>
#include <iostream>
#include <sstream> 
//-----------------------------------------------------------------------------------
#include <vector>
#include <map>
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

#include <cmath>
// https://codility.com/demo/results/demo8PH7UQ-Q6P/
int TestLargeSum(const std::vector < int > &A, int K,int LargeSum){
    int i,n,j;
    n = A.size();
    long long sum;

    sum=0;
    j=0;
    for (i=0;i < n;i++){
        sum += A[i];
        if (sum > LargeSum){
            j++;
            if (j > (K-1)) return 0;
            sum =A[i];
        }
    }
    return 1;
}

int solution(int K, int M, vector < int > &A){
  int i,n,Amax,LargeSum;
  int r,b,e,LargeSumR;
  
  n = A.size();
  LargeSum=0;
  for (i=K-1; i < n; i++) LargeSum += A[i];
  
  Amax=0;
  for (i=0;i < n;i++) if ( A[i] > Amax ) Amax=A[i];
  
  if (K==n) return Amax;
  LargeSum = max(Amax,LargeSum);
  
  b = Amax;
  e = LargeSum;
  if (e < b) swap(e,b);
  LargeSumR=e;
  
  // BinSearch
  while(b <= e){
    LargeSum = (b+e)/2;
    r = TestLargeSum(A,K,LargeSum);
    if(r){
      e = LargeSum -1;
      LargeSumR= LargeSum;
    } else
      b = LargeSum +1;    
  }
  return LargeSumR;
}


//-----------------------------------------------------------------------------------

int main(int argc,char *argv[]){
  if(argc < 2) {
    printf("You must provide at least one argument\n");
    exit(0);
  }
  string line;
  ifstream file;
  file.open(argv[1]);  
  while(getline(file, line)){

    int K,M;
    istringstream issK(line);
    issK >> K;
    cout << "K = " << K << endl;

    getline(file, line);
    istringstream issM(line);
    issM >> M;
    cout << "M = " << M << endl;

    getline(file, line);
    int i;
    vector<int> P;
    istringstream issP(line);
    while (issP >> i)
      P.push_back(i);
    print_v(P);   

    cout << "solution: " << solution(K,M,P) << endl;
  
  }
  cout << endl;
  return 0;
}
