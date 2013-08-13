/*Remove Element Feb 16 '125574 / 11584
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Author: Wencan Luo
Language: C++
Date: 08/12/2013
*/

#include<iostream>
using namespace std;
#include<climits>

#include<vector>
#include<string>
#include<algorithm>
#include<sstream>

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

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(n==0) return 0;

		int begin = 0;
		int end = n-1;
		while(begin < end){
			while(begin < n && A[begin] != elem) begin++;
			while(end >= 0 && A[end] == elem) end--;
			if(begin >= end) break;
			int t=A[begin];
			A[begin]= A[end];
			A[end] = t;
		}

		return begin-1;
    }

    int removeElement2(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int k = 0;
		for(int i=0;i<n;i++){
			if(A[i] != elem){
				if(k!=i){
					A[k] = A[i];
				}
				k++;
			}
		}

		return k;
    }
};

void main(){
    Solution s;
    
	system("pause");
}
