/*

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

int solution(vector<int> &A, vector<int> &B) {
  int N = A.size();
  int Num = N;
  stack <int> FishStack;
  int i = 0;
  while(B[i]==0 && i < N) i++;
  if(i==N) return N;
  FishStack.push(A[i]);
  for (int k=i+1; k < N;k++){
    if(B[k] == 1)
      FishStack.push(A[k]);
    else if (!FishStack.empty() 
          && FishStack.top() > A[k])
        Num--;  // A[k] is eaten
    else {
      while (!FishStack.empty() 
             && A[k] > FishStack.top()){
        FishStack.pop();
        Num--; // Fish in stack is eaten
      }
      if (!FishStack.empty() 
          && FishStack.top() > A[k])
        Num--;  // A[k] is eaten
    } 
  }
  return Num;
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
    getline(file, line);
    istringstream iss2(line);
    vector<int> B;
    while( iss2 >> number ) {
        B.push_back(number);
    }
    print_v(B);
   
    cout << solution(A,B) << endl;
  }
  return 0;
}
