/*
A zero-indexed array A consisting of N integers is given. A triplet (P, Q, R) is triangular if it is possible to build a triangle with sides of lengths A[P], A[Q] and A[R]. In other words, triplet (P, Q, R) is triangular if 0 ≤ P < Q < R < N and:
A[P] + A[Q] > A[R],
A[Q] + A[R] > A[P],
A[R] + A[P] > A[Q].
For example, consider array A such that:
  A[0] = 10    A[1] = 2    A[2] = 5
  A[3] = 1     A[4] = 8    A[5] = 12
There are four triangular triplets that can be constructed from elements of this array, namely (0, 2, 4), (0, 2, 5), (0, 4, 5), and (2, 4, 5).
Write a function:
int solution(const vector<int> &A);
that, given a zero-indexed array A consisting of N integers, returns the number of triangular triplets in this array.
For example, given array A such that:
  A[0] = 10    A[1] = 2    A[2] = 5
  A[3] = 1     A[4] = 8    A[5] = 12
the function should return 4, as explained above.
Assume that:
N is an integer within the range [0..1,000];
each element of array A is an integer within the range [1..1,000,000,000].
Complexity:
expected worst-case time complexity is O(N2);
expected worst-case space complexity is O(1), beyond input storage (not counting the storage required for input arguments).
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

int solution(const vector<int> &A) {
  int Asize = A.size();
  if (Asize < 3) return 0;
  vector <int> T(A);
  sort(T.begin(), T.end());
  int result = 0;
  for (int x = 0; x<Asize-2; x++){
    int z = x+2;
    for (int y= x+1; y<Asize-1; y++){
      while((z < Asize) && (T[x] + T[y] - T[z] > 0))
        z+=1;
      result += z - y - 1;
    }
  }
  return result;
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
    int i;
    vector<int> P;
    istringstream issP(line);
    while (issP >> i)
      P.push_back(i);
    print_v(P);   

    int R = solution(P);
    cout << R << endl;  
  }
  return 0;
}
