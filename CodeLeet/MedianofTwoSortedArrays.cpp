/*Median of Two Sorted ArraysMar 28 '116654 / 33995
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Author: Wencan Luo
Language: C++
Date: 08/15/2013
*/

#include<iostream>
using namespace std;
#include<climits>

#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
#include<stack>
#include<map>
//#include<unordered_set>

#include<queue>
#include<set>

// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int binarySearch(int A[], int begin, int end, int V){
       if(begin >= end) return -1;
       if(begin +1 == end){
           if(A[begin] == V) return begin;
           return -1;
       }
       
       int mid = (begin+end)/2;
       while(begin < end){
           if(A[mid] == V) return mid;
           if(A[mid] < V){
                
           }
       }
       
       return -1;
    }
    
    double findMedianSortedArraysRec(int A[], int begin, int end, int B[], int begin, int end) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        
    }
    
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return findMedianSortedArraysRec(A, 0, m, B, 0, n, )
    }
};

void main(){
    Solution s;

	system("pause");
}



