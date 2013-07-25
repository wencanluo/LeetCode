/*Search in Rotated Sorted ArrayMar 3 '125047 / 13245
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Author: Wencan Luo
Language: C++
Date: 07/24/2013
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
	int search_rec(int A[], int begin, int end, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(begin >= end) return -1;
		if(end == begin + 1){
			if(A[begin] == target) return begin;
			return -1;
		}

		int midValue = A[begin];
		int mid = (begin + end)/2;

		if(A[mid] > midValue){//left
			if(target > A[mid]){
				return search_rec(A, mid+1, end, target);
			}else if(target < A[mid]){
				if(target >= midValue){
					return search_rec(A, begin, mid, target);
				}else{
					return search_rec(A, mid+1, end, target);
				}
			}else{
				return mid;
			}
		}else if(A[mid] < midValue){//right
			if(target > A[mid]){
				if(target >= midValue){
					return search_rec(A, begin, mid, target);
				}else{
					return search_rec(A, mid+1, end, target);
				}
			}else if(target < A[mid]){
				return search_rec(A, begin, mid, target);
			}else{
				return mid;
			}
		}else{
			//search the left and search the right both
			int left = search_rec(A, begin, mid, target);
			if(left != -1) return left;

			int right = search_rec(A, mid+1, end, target);
			return right;
		}

		return -1;
    }

    int search1(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return search_rec(A, 0, n, target);
    }

	bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return search_rec(A, 0, n, target)!=-1;
    }
};

int main(){
	Solution s;
    
	int a[] = {1,3,1,1};
	int n= s.search(a, sizeof(a)/sizeof(a[0]), 3);

	cout << n << "\t" << a[n];
	system("pause");
    return 0;	
}
