/*
The prime is a positive integer X that has exactly two distinct divisors: 1 and X. The first few prime integers are 2, 3, 5, 7, 11 and 13.
The semiprime is a natural number that is the product of two (not necessarily distinct) prime numbers. The first few semiprimes are 4, 6, 9, 10, 14, 15, 21, 22, 25, 26.
You are given two non-empty zero-indexed arrays P and Q, each consisting of M integers. These arrays represent queries about the number of semiprimes within specified ranges.
Query K requires you to find the number of semiprimes within the range (P[K], Q[K]), where 1   P[K]   Q[K]   N.
For example, consider an integer N = 26 and arrays P, Q such that:

    P[0] = 1    Q[0] = 26
    P[1] = 4    Q[1] = 10
    P[2] = 16   Q[2] = 20

The number of semiprimes within each of these ranges is as follows:

(1, 26) is 10,
(4, 10) is 4,
(16, 20) is 0.
Write a function:

vector<int> solution(int N, vector<int> &P, vector<int> &Q);

that, given an integer N and two non-empty zero-indexed arrays P and Q consisting of M integers, returns an array consisting of M elements specifying the consecutive answers to all the queries.
For example, given an integer N = 26 and arrays P, Q such that:

    P[0] = 1    Q[0] = 26
    P[1] = 4    Q[1] = 10
    P[2] = 16   Q[2] = 20

the function should return the values [10, 4, 0], as explained above.
Assume that:
N is an integer within the range [1..50,000];
M is an integer within the range [1..30,000];
each element of arrays P, Q is an integer within the range [1..N];
P[i]   Q[i].
Complexity:
expected worst-case time complexity is O(N*log(log(N))+M);
expected worst-case space complexity is O(N+M), beyond input storage (not counting the storage required for input arguments).
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

void print_v(vector<int> &A){
  int N = A.size();
  cout << "Size: " << N << endl;
  for(int i=0;i<N;i++){
    cout << A[i] << " ";
  }
  cout << endl;
}


vector<int> generatePrimes(int N){  
  vector<int> NumbersSieve(N+1,1);
  NumbersSieve[0]=0;
  NumbersSieve[1]=0;
  for (int i = 2; i*i<=N; i++)
    if( NumbersSieve[i])      
      for(int k = i * i; k<=N; ){
        NumbersSieve[k]=0;
        k += i;
      }
  vector<int> Primes;
  for(int i=2; i<N+1;i++)
    if(NumbersSieve[i]) Primes.push_back(i);
  return Primes;
}


vector<int> generateSemiprimesCounters(int N){  
  vector<int> SemiPrimes(N+1,0);
  vector<int> Primes;
  Primes = generatePrimes(N/2); // N = 26, 2 * 2/3/5/7/11/13, 3 * 3/5/7, 5 * 5  
  int M = Primes.size();
  for(int i=0;i<M;i++){
      for(int k=i;k<M;k++)
        if (Primes[i] * Primes[k] <= N) 
          SemiPrimes[Primes[i] * Primes[k]] = 1;
        else break;
  }
  for(int i=4;i<N;i++)
    SemiPrimes[i+1] += SemiPrimes[i];
  
  return SemiPrimes;
}

vector<int> solution(int N, vector<int> &P, vector<int> &Q){
 
  int Psize = P.size();
  vector<int> Result(Psize, 0);
  vector<int> SemiPrimes = generateSemiprimesCounters(N);
  //print_v(SemiPrimes);

  for(int i=0;i<Psize;i++){
    Result[i] = SemiPrimes[Q[i]] - SemiPrimes[P[i] - 1];
  }
  return Result;
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
    istringstream iss(line);
    int N;
    iss >> N;
    cout << N << endl;

    vector<int> P;
    getline(file, line);
    int i;
    istringstream issP(line);
    while (issP >> i)
      P.push_back(i);
    print_v(P);   

    vector<int> Q;
    getline(file, line);
    istringstream issQ(line);
    while (issQ >> i)
      Q.push_back(i);
    print_v(Q);   

    vector<int> R;
    R = solution(N, P, Q);
    print_v(R);
  }
  return 0;
}
