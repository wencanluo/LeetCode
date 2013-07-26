/*Sort Colors Apr 9 '124095 / 9714
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
Note:
You are not suppose to use the library's sort function for this problem.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?

Author: Wencan Luo
Language: C++
Date: 07/26/2013
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
	void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
    }

    void sortColors_2pass(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int B[3];

		for(int i=0;i<3;i++){
			B[i] = 0;
		}

		for(int i=0;i<n;i++){
			B[ A[i] ]++;
		}

		int k=0;
		for(int i=0;i<B[0];i++){
			A[k++] = 0;
		}

		for(int i=0;i<B[1];i++){
			A[k++] = 1;
		}

		for(int i=0;i<B[2];i++){
			A[k++] = 2;
		}
    }
};

void main(){
	Solution s;
	
	int a[] = {1,2,1,0,2};

	s.sortColors(a, sizeof(a)/sizeof(a[0]));

	for(int i=0;i< sizeof(a)/sizeof(a[0]);i++){
		cout << a[i] << ",";
	}
	cout << endl;

	system("pause");
}
