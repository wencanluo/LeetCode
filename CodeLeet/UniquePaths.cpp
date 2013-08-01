/*Unique PathsMar 28 '124391 / 9799
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?



Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Author: Wencan Luo
Language: C++
Date: 07/31/2013
*/

#include<iostream>
using namespace std;
#include<climits>

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
 

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(m==0 || n==0) return 0;

		vector< vector<int> > M;
		M.resize(m);

		for(int i=0;i<m;i++){
			M[i].resize(n, 0);
		}

		for(int i=0;i<m;i++){
			M[i][0] = 1;
		}
		for(int j=0;j<n;j++){
			M[0][j] = 1;
		}

		for(int i=1;i<m;i++){
			for(int j=1;j<n;j++){
				M[i][j] = M[i-1][j] + M[i][j-1];
			}
		}

		return M[m-1][n-1];
    }

	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int m=obstacleGrid.size();
        if(m==0) return 0;
		int n=obstacleGrid[0].size();
		if(n==0) return 0;

		vector< vector<int> > M;
		M.resize(m);

		for(int i=0;i<m;i++){
			M[i].resize(n, 0);
		}

		for(int i=0;i<m;i++){
			if(1 == obstacleGrid[i][0]) break;
			M[i][0] = 1;
		}
		for(int j=0;j<n;j++){
			if(1 == obstacleGrid[0][j]) break;
			M[0][j] = 1;
		}

		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(1 == obstacleGrid[i][j]) M[i][j] = 0;
			}
		}

		for(int i=1;i<m;i++){
			for(int j=1;j<n;j++){
				if(1 != obstacleGrid[i][j]){
					M[i][j] = M[i-1][j] + M[i][j-1];
				}
			}
		}

		return M[m-1][n-1];
    }
};

void main(){
	Solution s;
	

	cout << s.uniquePaths(2,3);
	system("pause");
}
