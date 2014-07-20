/*
A DNA sequence can be represented as a string consisting of the letters A, C, G and T, which correspond to the types of successive nucleotides in the sequence. Each nucleotide has an impact factor, which is an integer. Nucleotides of types A, C, G and T have impact factors of 1, 2, 3 and 4, respectively. You are going to answer several queries of the form: What is the minimal impact factor of nucleotides contained in a particular part of the given DNA sequence?
The DNA sequence is given as a non-empty string S = S[0]S[1]...S[N-1] consisting of N characters. There are M queries, which are given in non-empty arrays P and Q, each consisting of M integers. The K-th query (0   K < M) requires you to find the minimal impact factor of nucleotides contained in the DNA sequence between positions P[K] and Q[K] (inclusive).
For example, consider string S = CAGCCTA and arrays P, Q such that:
    P[0] = 2    Q[0] = 4
    P[1] = 5    Q[1] = 5
    P[2] = 0    Q[2] = 6
The answers to these M = 3 queries are as follows:
The part of the DNA between positions 2 and 4 contains nucleotides G and C (twice), whose impact factors are 3 and 2 respectively, so the answer is 2.
The part between positions 5 and 5 contains a single nucleotide T, whose impact factor is 4, so the answer is 4.
The part between positions 0 and 6 (the whole string) contains all nucleotides, in particular nucleotide A whose impact factor is 1, so the answer is 1.
Write a function:
vector<int> solution(string &S, vector<int> &P, vector<int> &Q);
that, given a non-empty zero-indexed string S consisting of N characters and two non-empty zero-indexed arrays P and Q consisting of M integers, returns an array consisting of M integers specifying the consecutive answers to all queries.
The sequence should be returned as:
a Results structure (in C), or
a vector of integers (in C++), or
a Results record (in Pascal), or
an array of integers (in any other programming language).
For example, given the string S = CAGCCTA and arrays P, Q such that:
    P[0] = 2    Q[0] = 4
    P[1] = 5    Q[1] = 5
    P[2] = 0    Q[2] = 6
the function should return the values [2, 4, 1], as explained above.
Assume that:
N is an integer within the range [1..100,000];
M is an integer within the range [1..50,000];
each element of arrays P, Q is an integer within the range [0..N   1];
P[K]   Q[K], where 0   K < M;
string S consists only of upper-case English letters A, C, G, T.
Complexity:
expected worst-case time complexity is O(N+M);
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

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {    
  int strLen = S.size(); 
  vector< vector<int> > vec(strLen, vector<int>(4,0));
  const int A = 0;
  const int C = 1;
  const int G = 2;
  const int T = 3;

  char L = S[0];
  if (L=='A') vec[0][A]++; 
  else if (L=='C') vec[0][C]++; 
  else if (L=='G') vec[0][G]++; 
  else vec[0][T]++;

  for(int i=1;i < strLen;i++){
      L = S[i];
      
      vec[i][A] = vec[i-1][A]; 
      vec[i][C] = vec[i-1][C]; 
      vec[i][G] = vec[i-1][G]; 
      vec[i][T] = vec[i-1][T]; 

      if (L=='A') vec[i][A]++; 
      else if (L=='C') vec[i][C]++; 
      else if (L=='G') vec[i][G]++; 
      else vec[i][T]++;
  }

  int Psize = P.size();  
  vector< int > res(P.size(), 0);
  for(int i=0;i < Psize;i++){
      int Start = min(P[i],Q[i]);
      int End = max(P[i],Q[i]);
  
      if (Start == End){
        if (S[End] == 'A') res[i] = 1;
        else if (S[End] == 'C') res[i] = 2;
        else if (S[End] == 'G') res[i] = 3;
        else res[i] = 4;
      } else {            
        int maybeCat0 = 0;
        int maybeGat0 = 0;
        if (Start != 0) Start--;
        else {
          if (S[0]=='A') {
            res[i] = 1; 
            continue;
          } else if (S[0]=='C') 
            maybeCat0 = 1;
          else if (S[0]=='G') 
            maybeGat0 = 1;
        }                
        if ((vec[End][A] - vec[Start][A]) > 0 )
          res[i] = 1;
        else if((vec[End][C] - vec[Start][C]) > 0 || maybeCat0)
          res[i] = 2;
        else if((vec[End][G] - vec[Start][G]) > 0 || maybeGat0)
          res[i] = 3;
        else  res[i] = 4;
      }      
  }
  return res;

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
    string S;
    iss >> S;
    cout << "Size:"<< S.size() << endl << S << endl;

    getline(file, line);
    istringstream iss2(line);
    int number;
    vector<int> P;
    while( iss2 >> number ) {
        P.push_back(number);
    }
    print_v(P);    

    getline(file, line);
    istringstream iss3(line);
    int number2;
    vector<int> Q;
    while( iss3 >> number2 ) {
        Q.push_back(number2);
    }
    print_v(Q);
    
    vector<int> A = solution(S, P, Q);
    print_v(A);
  }
  return 0;
}
