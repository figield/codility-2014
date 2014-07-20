/*

In this problem we consider binary trees, represented by pointer data-structures. A pointer is called a binary tree if:

  it is an empty pointer (it is then called an empty tree); or
  it points to a structure (called a node) that contains a value and two pointers that are binary trees (called the left subtree and the right subtree).

A figure below shows a tree consisting of six nodes.
A path in a binary tree is a sequence of nodes one can traverse by following the pointers. More formally, a path is a sequence of nodes P[0], P[1], ..., P[K], such that node P[L] contains a pointer pointing to P[L + 1], for 0 < L < K. K is called the length of such a path.
The height of a binary tree is defined as the length of the longest possible path in the tree. In particular, a tree consisting only of just one node has height 0 and the height of an empty tree is undefined.
For example, consider the following tree:

           A
         /   \
        B     C
       / \    |
      D   E   F

Subtrees of nodes D, E and F are empty trees. Sequence A, B, E is a path of length 2. Sequence C, F is a path of length 1. Sequence E, B, D is not a valid path. The height of this tree is 2.
Assume that the following declarations are given:

  struct tree {
    int x;
    tree * l;
    tree * r;
  };

Write a function:

  int solution(tree * T);

that, given a non-empty binary tree T consisting of N nodes, returns its height.
For example, given tree T shown in the example above, the function should return 2.
Assume that:

  N is an integer within the range [1..1,000].

Complexity:

  expected worst-case time complexity is O(N);
  expected worst-case space complexity is O(N).

*/
 
#include <fstream>
#include <iostream>
#include <sstream> 
//-----------------------------------------------------------------------------------
#include <stdlib.h>

using namespace std;

struct tree {
  int x;
  tree * l;
  tree * r;
};

int go_down(tree * n, int deep){
  if(n != NULL)
    return max(go_down(n->l, deep+1),
               go_down(n->r, deep+1));
  else return deep - 1;
}

int solution(tree * n0) {
  return go_down(n0, 0);
}


//-----------------------------------------------------------------------------------

int main(int argc,char *argv[]){

  tree * n0 = new tree;
  n0->x = 5;
  tree * nL1 = new tree;
  nL1->x = 3;
  tree * nP1 = new tree;
  nP1->x = 10;
  tree * nL1L2 = new tree;
  nL1L2->x = 20;
  tree * nL1P2 = new tree;
  nL1P2->x = 21;
  tree * nP1L2 = new tree;
  nP1L2->x = 1; 
  tree * nP1L2L3 = new tree;

  n0->l = nL1;
  n0->r = nP1;
  nL1->l = nL1L2;
  nL1->r = nL1P2;
  nP1->l = nP1L2; 
  nP1->r = NULL;
  nP1L2->l = nP1L2L3;

  cout << "Result:"<< solution(n0) << endl;

  return 0;
}
