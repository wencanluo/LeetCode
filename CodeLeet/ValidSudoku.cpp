/*Valid Sudoku Mar 3 '123119 / 9316
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.



A partially filled sudoku which is valid.

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
	bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = board.size();

		bool valid = true;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(!Check(board, i, j)) return false;
			}
		}
		return true;
    }

	bool Check(vector<vector<char> > &A, int i, int j){
		if(A[i][j] == '.') return true;

		int n = A.size();
		char m = A[i][j];
		//check row
		for(int q=0;q<n;q++){
			if(q == i) continue;
			if( A[q][j] == m) return false;
		}
		
		//check col
		for(int q=0;q<n;q++){
			if(q == j) continue;
			if( A[i][q] == m) return false;
		}
		
		//check square
		for(int q=0;q<3;q++){
			for(int p=0;p<3;p++){
				if(3*(i/3) + q == i && 3*(j/3) + p == j) continue;
				if( A[3*(i/3) + q][3*(j/3) + p] == m) return false;
			}
		}
		
		return true;
	}
};

void main(){
	Solution s;
	
	char a[9][10] = { 
		"...2...63","3....54.1","..1..398.",".......9.","...538...",".3.......",".263..5..","5.37....8","47...1..."
		};

	vector< vector<char> > A;
	A.resize(9);
	for(int i=0;i<9;i++){
		vector<char> t(a[i], a[i]+9);
		A[i] = t;
	}
	
	cout << s.isValidSudoku(A);


	system("pause");
}
