/*

A non-empty zero-indexed array A consisting of N numbers is given. The array is sorted in non-decreasing order. The absolute distinct count of this array is the number of distinct absolute values among the elements of the array.
For example, consider array A such that:
  A[0] = -5    
  A[1] = -3    
  A[2] = -1
  A[3] =  0    
  A[4] =  3    
  A[5] =  6
The absolute distinct count of this array is 5, because there are 5 distinct absolute values among the elements of this array, namely 0, 1, 3, 5 and 6.
Write a function:
int solution(const vector<int> &A);
that, given a non-empty zero-indexed array A consisting of N numbers, returns absolute distinct count of array A.
For example, given array A such that:
  A[0] = -5    
  A[1] = -3    
  A[2] = -1
  A[3] =  0    
  A[4] =  3    
  A[5] =  6
the function should return 5, as explained above.
Assume that:
N is an integer within the range [1..100,000];
each element of array A is an integer within the range [ 2,147,483,648..2,147,483,647];
array A is sorted in non-decreasing order.
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
#include <algorithm>
#include <stdlib.h>
using namespace std;

// it is like a cheating ;), O(N*log(N))
#include <map>
int solution_cheating(const vector<int> &A) {
    int n = A.size();
    if (n < 2) return n;

    map<long int, int> count;
    for (int i = 0; i < n; ++i)
      ++count[abs(A[i])];
    
    return count.size();
}

// Implemented according to solution from http://codesays.com/2014/solution-to-abs-distinct-by-codility/
// 92%, O(N*log(N)), problem with arith_overlow, got 4 expected 3
// python version is working fine...
int solution92(const vector<int> &A) {
  int Asize = A.size();
  if (Asize <= 1) return Asize; 
  int count = 1;
  int index_left = 0;
  int index_right = Asize -1;
  long int current = max((long int)abs((long int)A[0]), (long int)abs(A[Asize-1]));

  while (index_left <= index_right){
    //cout << current << endl;
    //  We travel the array from the greatest
    //  absolute value to the smallest.
    long int former = abs((long int)A[index_left]);
    if (former == current){
      // Skip the heading elements, whose
      // absolute values are the same with
      // current recording one.
      index_left++;
      continue;
    }
    long int latter = abs((long int)A[index_right]);
    if (latter == current){
      // Skip the tailing elements, whose
      // absolute values are the same with
      // current recording one.
      index_right--;
      continue;
    }
    // At this point, both the former and
    // latter has different absolute value
    // from current recorded one.
    if (former >= latter){
      // The next greatest value is former
      current = former;
      index_left++;
    }
    else {
      // The next greatest value is latter
      current = latter;
      index_right--;
    }
    // Meet with a new absolute value
    count++;
  }
  return count;
}

// my solution
// 100% but O(N*log(N))
// https://codility.com/demo/results/demo4NK4XX-MJ3/
int solution(const vector<int> &A) {

  int Asize = A.size();
  if (Asize <= 1) return Asize;
  int count = 1;
  int index_left = 0;
  int index_right = Asize -1;
  long int dist_value;

  if(abs((long int)A[0]) == abs((long int)A[Asize-1])){
    dist_value = abs((long int)A[0]);
    index_right--;
    index_left++;
  } else if(abs((long int)A[0]) > abs((long int)A[Asize-1])){
    dist_value = abs((long int)A[0]);
    index_left++;
  } else {
    dist_value = abs((long int)A[Asize-1]);
    index_right--;
  }

  while (index_left < index_right){
    int val_left = abs((long int)A[index_left]);
    int val_right = abs((long int)A[index_right]);

    if (val_right > val_left){
      if(val_right < dist_value){
        dist_value = val_right;
        count++;
      }
      index_right--;
    } else if (val_right < val_left){
      if(val_left < dist_value){
        dist_value = val_left;
        count++;
      }
      index_left++;
    } else {
      if(val_left < dist_value){
        dist_value = val_left;
        count++;
      }
      index_right--;      
      index_left++;
    }
  }

  if (abs((long int)A[index_left]) != dist_value)
    count++;

  return count;
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

    cout << "solution: " << solution(P) << endl;
  
  }
  cout << endl;
  int int_minus = -2147483648;
  cout << "abs int_minus (-2147483648):" << abs(int_minus) << endl;
  long int long_minus = -2147483648;
  cout << "abs long_minus (-2147483648):" << abs(long_minus) << endl;
  cout << "max long_minus: "<< max(abs(long_minus), (long int) 2147483647) << endl;
  return 0;
}
