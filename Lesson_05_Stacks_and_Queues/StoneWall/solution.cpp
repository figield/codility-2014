/*
You are going to build a stone wall. The wall should be straight and N meters long, and its thickness should be constant; however, it should have different heights in different places. The height of the wall is specified by a zero-indexed array H of N positive integers. H[I] is the height of the wall from I to I+1 meters to the right of its left end. In particular, H[0] is the height of the wall's left end and H[N−1] is the height of the wall's right end.
The wall should be built of cuboid stone blocks (that is, all sides of such blocks are rectangular). Your task is to compute the minimum number of blocks needed to build the wall.
Write a function:
int solution(const vector<int> &H);
that, given a zero-indexed array H of N positive integers specifying the height of the wall, returns the minimum number of blocks needed to build it.
For example, given array H containing N = 9 integers:
  H[0] = 8    H[1] = 8    H[2] = 5    
  H[3] = 7    H[4] = 9    H[5] = 8    
  H[6] = 7    H[7] = 4    H[8] = 8    
the function should return 7. The figure shows one possible arrangement of seven blocks.

Assume that:
N is an integer within the range [1..100,000];
each element of array H is an integer within the range [1..1,000,000,000].
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
#include <stack>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int solution(const vector<int> &H) {
  int N = H.size();
  if (N <= 1) return N;
  int blockCount = 0;
  stack <int> heights;  

  for (int i=0;i<N;i++){ 
    while (!heights.empty() 
           && H[i] < heights.top()){
      heights.pop();
      blockCount++;
    }
    if(heights.empty()){
      heights.push(H[i]);
      continue;
    }
 
    if(H[i] > heights.top())
      heights.push(H[i]); 
  }
  return blockCount + heights.size();
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
