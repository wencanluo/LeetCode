/*Search Insert PositionMar 3 '125036 / 10139
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

Author: Wencan Luo
Language: C++
Date: 08/11/2013
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

// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		//binary search
		if(n<=0) return 0;
		if(target <= A[0]) return 0;

		if(n==1){
			if(target == A[0]) return 0;
			return 1;
		}

		int begin = 0;
		int end = n;
		int mid;
		
		while(begin < end){
			mid = (begin + end) /2;

			if(A[mid] == target){
				return mid;
			}else if(A[mid] < target){
				begin = mid + 1;
			}else{
				end = mid;
			}
		}
		
		return begin;
    }
};

void main(){
	Solution s;
	
	int a[] = {1,2,4};

	cout << s.searchInsert(a, sizeof(a)/sizeof(a[0]), 3);


	system("pause");
}
