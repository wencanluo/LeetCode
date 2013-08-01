/*Search a 2D Matrix Apr 7 '123960 / 8847
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.

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
	bool searchMatrixRec(vector<vector<int> > &matrix, int begin, int end, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int n=matrix.size();
		if(n<=0) return false;
		int m=matrix[0].size();
		
		if(end <= begin) return false;

		int mid = (end+begin)/2;

		int x = mid/m;
		int y = mid%m;

		if(matrix[x][y] == target) return true;

		if(matrix[x][y] < target) return searchMatrixRec(matrix, mid+1, end, target);

		return searchMatrixRec(matrix, begin, mid, target);
    }

    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		int n=matrix.size();
		if(n<=0) return false;
		int m=matrix[0].size();

		return searchMatrixRec(matrix, 0, n*m, target);
    }
};

void main(){
	Solution s;
	
	vector<int> a;
	a.push_back(1);
	a.push_back(2);

	vector< vector<int> > b;
	b.push_back(a);

	cout << s.searchMatrix(b, 1);
	system("pause");
}
