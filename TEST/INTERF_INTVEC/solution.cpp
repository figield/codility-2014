/*

*/

#include <fstream>
#include <iostream>
#include <sstream> 
//-----------------------------------------------------------------------------------
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;


int solution(int K, vector<int> &A) {
  int R = 0;
  int N = A.size();
  long long L = -K;
  for(int i = 0; i<N; i++){
    L += A[i]; 
    if (L >= 0){
      R++;
      L = -K;
    }
  }
  return R;
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

    int K;
    istringstream issK(line);
    issK >> K;

    getline(file, line);
    int i;
    vector<int> P;
    istringstream issP(line);
    while (issP >> i)
      P.push_back(i);
    print_v(P);   

    cout << "solution: " << solution(K, P) << endl;
    cout << endl;  
  }


  return 0;
}
