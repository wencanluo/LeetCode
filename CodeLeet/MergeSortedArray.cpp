/*Merge Sorted ArrayMay 20 '124065 / 9128
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.

Author: Wencan Luo
Language: C++
Date: 07/18/2013
*/

#include<iostream>
using namespace std;

#include<vector>
#include<string>
#include<algorithm>

#include<map>
//#include<unordered_set>

#include<queue>
#include<set>
#include<stack>

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
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if(n==0) return;

        int i=m-1;
		int j=n-1;
		int k=m+n-1;

		while(i>=0 && j>=0){
			if(A[i] > B[j]){
				A[k] = A[i];
				i--;
			}else{
				A[k] = B[j];
				j--;
			}
			k--;
		}

		while(j>=0){
			A[k] = B[j];
			j--;
			k--;
		}
    }
};

void main(){
	Solution s;
	
	int A[] = {1,2,7,0,0,0};
	int B[] = {0,5,6};

	s.merge(A,3,B,3);
	
	system("pause");
}
