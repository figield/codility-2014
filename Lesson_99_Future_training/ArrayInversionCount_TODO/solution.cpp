/*
A zero-indexed array A consisting of N integers is given. An inversion is a pair of indexes (P, Q) such that P < Q and A[Q] < A[P].
Write a function:

  int solution(const vector<int> &A);

that computes the number of inversions in A, or returns −1 if it exceeds 1,000,000,000.
Assume that:
  N is an integer within the range [0..100,000];
  each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].

For example, in the following array:
  A[0] = -1 A[1] = 6 A[2] = 3
  A[3] =  4 A[4] = 7 A[5] = 4

there are four inversions:
  (1,2)  (1,3)  (1,5)  (4,5)

so the function should return 4.

Complexity:
  expected worst-case time complexity is O(N*log(N));
  expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).

*/


#include <fstream>
#include <iostream>
#include <sstream> 
//-----------------------------------------------------------------------------------
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

/*
def mergesort( aList, first, last ):
    ''' Modified merge sort algorithm.
        Record the inversion count during sort.
    '''
    mid = ( first + last ) / 2
    if first < last:
        # Recursive calling
        left_inver = mergesort( aList, first, mid )
        right_inver = mergesort( aList, mid + 1, last )
    else:
        # Terminate condition
        return 0

    first_index = first     # The index for the left part
    second_index = mid + 1  # The index for the right part
    temp = [0] * (last-first+1)     # To hold the sorted content
    temp_index = 0
    merge_inver = 0         # Number of inversion in merging

    while first_index <= mid and second_index <= last:
        if aList[first_index] <= aList[second_index]:
            # Less index indicates less value. No inversion.
            temp[temp_index] = aList[first_index]
            first_index += 1
        else:
            # Greater index has less value. Inversion exists.
            # For exampe:
            #       [     4,   5,   2,   3     ]
            #       | Left part |  |Right Part|
            # and first_index = 1, second_index = 3, mid = 2
            # We need the item "2" to be the position 0. So it
            # has to pass all the unwritten items in left part.
            # Here these unwritten items are "4" and "5". So
            # two more inversions are involved.
            # In general, the left part is sorted. So all the
            # elements, being and after first_index, are greater
            # than element in position second_index. AND all of
            # them have less indexes. As the result, 
            # there are mid-first_index+1 new reversions.
            temp[temp_index] = aList[second_index]
            second_index += 1
            merge_inver += mid - first_index + 1
        temp_index += 1

    if first_index != mid+1:
        # Some element in the left part left. They have less
        # indexes, but greater values. Inversion involves.
        # BUT these inversions have already been counted.
        while first_index <= mid:
            temp[temp_index] = aList[first_index]
            first_index += 1
            temp_index += 1

    if second_index != last+1:
        # Some element in the right part left. They have both
        # greater indexes and values than all in the left part.
        # No inversion is involved.
        while second_index <= last:
            temp[temp_index] = aList[second_index]
            second_index += 1
            temp_index += 1

    # Rewrite the sorted content into the original array
    aList[first:last+1] = temp[:]

    return merge_inver + left_inver + right_inver

def solution(A):
    return mergesort( A * 1, 0, len(A)-1)
*/

// Modified merge sort algorithm.
// Record the inversion count during sort.
int mergesort(vector<int> & aList, int first, int last){
  cout << "first1: " << first << endl;
  cout << "last1: " << last << endl;
  int mid = (int)(first + last) / 2;
  int left_inver;
  int right_inver;
  if (first < last){
    // Recursive calling
    left_inver = mergesort(aList, first, mid);
    right_inver = mergesort(aList, mid + 1, last);
  }
  else
      // Terminate condition
    return 0;

  int first_index = first;            // The index for the left part
  int second_index = mid + 1;         // The index for the right part
  cout << "last-first+1: " << last-first+1 << endl;
  vector<int>  temp(last-first+1, 0); // To hold the sorted content
  int temp_index = 0;
  int merge_inver = 0;                // Number of inversion in merging


  while ((first_index <= mid) && (second_index <= last)){
    if (aList[first_index] <= aList[second_index]){
      // Less index indicates less value. No inversion.
      temp[temp_index] = aList[first_index];
      first_index += 1;
    } else {
      // Greater index has less value. Inversion exists.
      // For exampe:
      //       [     4,   5,   2,   3     ]
      //       | Left part |  |Right Part|
      // and first_index = 1, second_index = 3, mid = 2
      // We need the item "2" to be the position 0. So it
      // has to pass all the unwritten items in left part.
      // Here these unwritten items are "4" and "5". So
      // two more inversions are involved.
      // In general, the left part is sorted. So all the
      // elements, being and after first_index, are greater
      // than element in position second_index. AND all of
      // them have less indexes. As the result, 
      // there are mid-first_index+1 new reversions.
      temp[temp_index] = aList[second_index];
      second_index += 1;
      merge_inver += mid - first_index + 1;
      temp_index += 1;
    }
    temp_index += 1;
  }

  if (first_index != mid+1)
    // Some element in the left part left. They have less
    // indexes, but greater values. Inversion involves.
    // BUT these inversions have already been counted.
    while (first_index <= mid){
      temp[temp_index] = aList[first_index];
      first_index += 1;
      temp_index += 1;
    }

  if (second_index != last+1)
    // Some element in the right part left. They have both
    // greater indexes and values than all in the left part.
    // No inversion is involved.
    while (second_index <= last){
      temp[temp_index] = aList[second_index];
      second_index += 1;
      temp_index += 1;
    }

  // Rewrite the sorted content into the original array
  cout << "first2: " << first << endl;
  cout << "last2: " << last << endl;
  for (int i = first; i <= last;i++) aList[i] = temp[i];
  
  cout << "ok"  << endl;
  return merge_inver + left_inver + right_inver;
}

int solution(vector<int> &A) {
  return mergesort(A, 0, A.size()-1);
}

// 80%, O(N**2)
int solution2(vector<int> &A) {
  int R = 0;
  int N = A.size();

  for(int i = 0; i<N-1; i++)
    for (int k = i+1; k<N; k++){
      if (A[i] > A[k]) R++;
      if (R > 1000000000) return -1;
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

    int i;
    vector<int> P;
    istringstream issP(line);
    while (issP >> i)
      P.push_back(i);
    print_v(P);   
    cout << "solution: " << solution(P) << endl << endl;  
  }
  return 0;
}
