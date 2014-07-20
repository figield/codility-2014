/*

Some notes and code how to read input data from file/IO

*/

#include <fstream>
#include <iostream>
#include <sstream> 
#include <vector>
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

void read_data(vector<int> &A, char *FileName){
  ifstream file;
  file.open(FileName);
  int i;
  while (file >> i)
    A.push_back(i);
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
     
  }
  return 0;
}




/*
#include <iostream> 
#include <fstream> 
#include <sstream> 
using namespace std; 

int main() { 
  ifstream fin("example.txt"); 
  string line; 
  while (getline(fin, line)) { 
    cout << line << endl; 
    istringstream tokenizer(line); 
    string token; 
    getline(tokenizer, token, ','); 
    istringstream float_iss(token); 
    float f; 
    float_iss >> f; 
  
    cout << f << endl; 
    getline(tokenizer, token, ','); 

    cout << token << endl; 
    getline(tokenizer, token, ','); 

    istringstream int_iss(token); 
    int i; 
    int_iss >> i; 
    cout << i << endl; 
  } 
  return 0; 
}
*/ 
// - See more at: https://www.gidforums.com/t-18285.html#sthash.PKIdQufZ.dpuf
