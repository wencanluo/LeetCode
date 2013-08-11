/*Search for a Range Mar 3 '125093 / 13502
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

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
	int binarySearchLeft(int A[], int n, int target){//search left
		if(n<=0) return -1;
		if(A[0] == target) return 0;

		int begin = 0;
		int end = n;
		int mid;
		
		while(begin < end){
			mid = (begin + end) /2;

			if(A[mid] == target){
				if(A[mid-1] == target){
					end = mid;
				}else{ //A[mid-1]<target
					return mid;
				}			
			}else if(A[mid] < target){
				begin = mid + 1;
			}else{
				end = mid;
			}
		}
		
		return -1;
	}

	int binarySearchRight(int A[], int n, int target){//search left
		if(n<=0) return -1;
		if(A[n-1] == target) return n-1;

		int begin = 0;
		int end = n;
		int mid;
		
		while(begin < end){
			mid = (begin + end) /2;

			if(A[mid] == target){
				if(A[mid+1] == target){
					begin = mid;
				}else{ //A[mid-1]<target
					return mid;
				}			
			}else if(A[mid] < target){
				begin = mid + 1;
			}else{
				end = mid;
			}
		}
		
		return -1;
	}

    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<int> r;
		r.push_back(binarySearchLeft(A, n, target));
		r.push_back(binarySearchRight(A, n, target));
		return r;
    }
};

void main(){
	Solution s;
	
	int a[] = {5, 7, 7, 8, 8, 10};

	cout << s.binarySearchLeft(a, sizeof(a)/sizeof(a[0]), 7) << endl;
	cout << s.binarySearchRight(a, sizeof(a)/sizeof(a[0]), 7) << endl;
	system("pause");
	return;

	vector<int> r;

	r = s.searchRange(a, sizeof(a)/sizeof(a[0]), 3);
	cout << r[0] << "\t" << r[1] << endl;

	r = s.searchRange(a, sizeof(a)/sizeof(a[0]), 7);
	cout << r[0] << "\t" << r[1] << endl;

	r = s.searchRange(a, sizeof(a)/sizeof(a[0]), 11);
	cout << r[0] << "\t" << r[1] << endl;

	system("pause");
}
