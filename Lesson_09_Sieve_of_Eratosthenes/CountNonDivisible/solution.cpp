/*

You are given a non-empty zero-indexed array A consisting of N integers.
For each number A[i] such that 0   i < N, we want to count the number of elements of the array that are not the divisors of A[i]. We say that these elements are non-divisors.
For example, consider integer N = 5 and array A such that:
    A[0] = 3
    A[1] = 1
    A[2] = 2
    A[3] = 3
    A[4] = 6
For the following elements:
A[0] = 3, the non-divisors are: 2, 6,
A[1] = 1, the non-divisors are: 3, 2, 3, 6,
A[2] = 2, the non-divisors are: 3, 3, 6,
A[3] = 3, the non-divisors are: 2, 6,
A[6] = 6, there aren't any non-divisors.
Write a function:
vector<int> solution(vector<int> &A);
that, given a non-empty zero-indexed array A consisting of N integers, returns a sequence of integers representing the amount of non-divisors.
The sequence should be returned as:
a structure Results (in C), or
a vector of integers (in C++), or
a record Results (in Pascal), or
an array of integers (in any other programming language).
For example, given:
    A[0] = 3
    A[1] = 1
    A[2] = 2
    A[3] = 3
    A[4] = 6
the function should return [2, 4, 3, 2, 0], as explained above.
Assume that:
N is an integer within the range [1..50,000];
each element of array A is an integer within the range [1..2 * N].
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

vector<int> solution(vector<int> &A){

  int N = A.size();
  int MaxNum = *max_element(A.begin(), A.end());
  vector<int> Occurence(MaxNum + 1, 0);
  vector<int> NonDivisors(MaxNum + 1, 0);
  vector<int> Result(N,0);  

  // Calculate occurences of each number in the array
  for (int i = 0; i < N; ++i) Occurence[A[i]] += 1;
  
  for (int i=0;i<N;i++){    
    if(NonDivisors[A[i]]==0){ // to calculate only one time for the same value

      int divisors = 0;
      for(int j = 1; j*j<=A[i];j++){
        if (A[i] % j == 0){
          divisors += Occurence[j]; 
          if (A[i] != j*j) divisors += Occurence[(int)(A[i] / j)];         
        }        
      }
      Result[i] = N - divisors;
      NonDivisors[A[i]] = Result[i];
    } else {
       Result[i] = NonDivisors[A[i]];
    }

  }
  return Result;
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
    vector<int> B;
    B = solution(A);
    print_v(B);
  }
  return 0;
}
