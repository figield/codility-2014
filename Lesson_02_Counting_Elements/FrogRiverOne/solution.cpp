/*

A small frog wants to get to the other side of a river. The frog is currently located at position 0, and wants to get to position X. Leaves fall from a tree onto the surface of the river.
You are given a non-empty zero-indexed array A consisting of N integers representing the falling leaves. A[K] represents the position where one leaf falls at time K, measured in minutes.
The goal is to find the earliest time when the frog can jump to the other side of the river. The frog can cross only when leaves appear at every position across the river from 1 to X.
For example, you are given integer X = 5 and array A such that:
  A[0] = 1
  A[1] = 3
  A[2] = 1
  A[3] = 4
  A[4] = 2
  A[5] = 3
  A[6] = 5
  A[7] = 4
In minute 6, a leaf falls into position 5. This is the earliest time when leaves appear in every position across the river.
Write a function:
int solution(int X, vector<int> &A);
that, given a non-empty zero-indexed array A consisting of N integers and integer X, returns the earliest time when the frog can jump to the other side of the river.
If the frog is never able to jump to the other side of the river, the function should return −1.
For example, given X = 5 and array A such that:
  A[0] = 1
  A[1] = 3
  A[2] = 1
  A[3] = 4
  A[4] = 2
  A[5] = 3
  A[6] = 5
  A[7] = 4
the function should return 6, as explained above. Assume that:
N and X are integers within the range [1..100,000];
each element of array A is an integer within the range [1..X].
Complexity:
expected worst-case time complexity is O(N);
expected worst-case space complexity is O(X), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.

*/

#include <fstream>
#include <iostream>
#include <sstream> 
//-----------------------------------------------------------------------------------
#include <vector>
#include <stdlib.h>
using namespace std;


int solution(int X, vector<int> &A){
  
  int max_t = -1;
  int all = 0;
  int *positions = new int[X];
  for (int i=0; i<X; i++) 
    positions[i] = -1;
 
  int N = A.size();
  for (int t=0; t<N; t++) 
    if (positions[A[t]-1]==-1){
      positions[A[t]-1] = t;
      max_t = t;
      all++;
      if (all == X) return max_t;
    }

  if (all < X) return -1;

  return max_t;
}


/*
#include<climits>  
int solution(int X, vector<int> &A) {
    // write your code in C++98
    //out of range
    if(X > A.size()) return -1;  

    vector<int> timeOfPos(X+1, -1);  
    for(int i = 0; i < A.size(); ++i)  
        timeOfPos[A[i]] = timeOfPos[A[i]] == -1 ? i : min(i, timeOfPos[A[i]]);  
  
    int maxSingleTime = INT_MIN;  
    for(int i = 1; i < timeOfPos.size(); ++i)  
        if(timeOfPos[i] == -1) return -1;  
        else maxSingleTime = max(timeOfPos[i], maxSingleTime);  

    return maxSingleTime;
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
    cout << solution(5, A) << endl;
  }
  return 0;
}
