/*Set Matrix ZeroesApr 6 '123324 / 7762
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Author: Wencan Luo
Language: C++
Date: 07/29/2013
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
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = matrix.size();
		if(n==0) return;

		int m = matrix[0].size();

		bool row = false;
		bool col = false;
		for(int i=0;i<n;i++){
			if(matrix[i][0] == 0){
				col = true;
				break;
			}
		}

		for(int j=0;j<m;j++){
			if(matrix[0][j] == 0){
				row = true;
				break;
			}
		}

		for(int i=1;i<n;i++){
			for(int j=1;j<m;j++){
				if(matrix[i][j] == 0){
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}

		for(int i=1;i<n;i++){
			for(int j=1;j<m;j++){
				if(matrix[0][j] == 0 || matrix[i][0] == 0){
					matrix[i][j] = 0;
				}
			}
		}

		if(col){
			for(int i=0;i<n;i++){
				matrix[i][0] = 0;
			}
		}

		if(row){
			for(int j=0;j<m;j++){
				matrix[0][j] = 0;
			}
		}
    }
};

void main(){
	Solution s;
	
	int a[] = {1,1,1};
	int b[] = {0,1,0};
	int c[] = {1,1,0};
	vector<int> va(a, a+sizeof(a)/sizeof(a[0]));
	vector<int> vb(b, b+sizeof(b)/sizeof(b[0]));
	vector<int> vc(c, c+sizeof(c)/sizeof(c[0]));

	vector< vector<int> > M;
	M.push_back(va);
	M.push_back(vb);
	M.push_back(vc);

	s.setZeroes(M);

	for(int i=0;i<M.size();i++){
		for(int j=0;j<M[0].size();j++){
			cout << M[i][j] << "\t";
		}
		cout << endl;
	}

	system("pause");
}
