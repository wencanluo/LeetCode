/*Minimum Path Sum Mar 29 '123383 / 7463
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time

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
	struct mycompare {
	  bool operator() (pair<int,long> a, pair<int,long> b) { return (a.second > b.second);  }
	};

	pair<int,int> getXY(int p, int m){
		return make_pair(p/m, p%m);
	}

	int getP(int x, int y, int m){
		return x*m+y;
	}

    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n=grid.size();
		if(n<=0) return 0;
		int m=grid[0].size();
		
		vector<vector<long> >M;
		M.resize(n);
		for(int i=0;i<n;i++){
			M[i].resize(m, INT_MAX);
		}

		M[0][0] = grid[0][0];

		//BFS
		priority_queue<pair<int,long>, vector<pair<int,long>>, mycompare> Q;
		Q.push(make_pair(getP(0,0,m), M[0][0]));

		while(!Q.empty()){
			pair<int,long> pD = Q.top();
			pair<int, int> p = getXY(pD.first, m);
			Q.pop();

			if(p.first == n-1 && p.second ==m-1){
				return pD.second;
			}

			int x=p.first + 1;
			int y=p.second;

			if(x < n) {
				if(grid[x][y] + M[p.first][p.second] < M[x][y]){
					M[x][y] = grid[x][y] + M[p.first][p.second];
					Q.push(make_pair(getP(x,y,m),M[x][y]));
				}
			}

			/*x=p.first - 1;
			y=p.second;
			if(x > 0) {
				if(grid[x][y] + M[p.first][p.second] < M[x][y]){
					M[x][y] = grid[x][y] + M[p.first][p.second];
					Q.push(make_pair(getP(x,y,m),M[x][y]));
				}
			}*/

			x=p.first;
			y=p.second+1;
			if(y < m) {
				if(grid[x][y] + M[p.first][p.second] < M[x][y]){
					M[x][y] = grid[x][y] + M[p.first][p.second];
					Q.push(make_pair(getP(x,y,m),M[x][y]));
				}
			}

			/*
			x=p.first;
			y=p.second-1;
			if(y > 0) {
				if(grid[x][y] + M[p.first][p.second] < M[x][y]){
					M[x][y] = grid[x][y] + M[p.first][p.second];
					Q.push(make_pair(getP(x,y,m),M[x][y]));
				}
			}*/
		}

		return 0;
    }
};

void main(){
	Solution s;
	
	int a[] = {1,2,3};
	int b[] = {1,2,3};

	vector<int> va(a, a+sizeof(a)/sizeof(a[0]));
	vector<int> vb(b, b+sizeof(b)/sizeof(b[0]));

	vector< vector<int> > v;
	v.push_back(va);
	v.push_back(vb);

	cout << s.minPathSum(v);
	system("pause");
}
