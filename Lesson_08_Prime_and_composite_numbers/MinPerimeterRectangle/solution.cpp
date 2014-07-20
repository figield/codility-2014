/*
An integer N is given, representing the area of some rectangle.
The area of a rectangle whose sides are of length A and B is A * B, and the perimeter is 2 * (A + B).
The goal is to find the minimal perimeter of any rectangle whose area equals N. The sides of this rectangle should be only integers.
For example, given integer N = 30, rectangles of area 30 are:
(1, 30), with a perimeter of 62,
(2, 15), with a perimeter of 34,
(3, 10), with a perimeter of 26,
(5, 6), with a perimeter of 22.
Write a function:
int solution(int N);
that, given an integer N, returns the minimal perimeter of any rectangle whose area is exactly equal to N.
For example, given an integer N = 30, the function should return 22, as explained above.
Assume that:
N is an integer within the range [1..1,000,000,000].
Complexity:
expected worst-case time complexity is O(sqrt(N));
expected worst-case space complexity is O(1).
*/

#include <fstream>
#include <iostream>
#include <sstream> 
//-----------------------------------------------------------------------------------
#include <vector>
#include <stdlib.h>
#include <math.h>  
using namespace std;

int solution(int N){
  for(int i=(int)sqrt(N); i >= 1;i--) 
    if (N % i ==0) return 2 * (i + (int)(N/i));

  return 0;
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
    cout << solution(A[0]) << endl;
  }
  return 0;
}
