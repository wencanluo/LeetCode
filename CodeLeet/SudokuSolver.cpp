/*Sudoku SolverMar 4 '122939 / 11019
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.


A sudoku puzzle...



...and its solution numbers marked in red.

Author: Wencan Luo
Language: C++
Date: 08/10/2013
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
	bool SolveSudokuRec(vector<vector< vector<int> > > &A){
		int n = A.size();

		bool solved = false;
		bool NotSame = true;
		while(NotSame){
			NotSame = false;
			solved = true;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(A[i][j].size() > 1){
						bool Changed = Check(A, i, j);
						if(Changed){
							NotSame = true;
						}
					}
					if(A[i][j].size() == 0) return false;
					if(A[i][j].size() != 1) solved = false;					
				}
			}
		}

		if(solved) {
			return true;//done
		}

		//recursive
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(A[i][j].size() > 1){
					vector<int> t = A[i][j];
					for(int k=0;k<t.size();k++){
						vector<int> assume;
						assume.push_back(t[k]);
						A[i][j] = assume;
						
						vector<vector< vector<int> > > T = A;
						bool subsolved = SolveSudokuRec(T);
						if(subsolved){
							A = T;
							return true;
						}
					}
					return false;
				}
			}
		}

		return false;
	}

	bool Check(vector<vector< vector<int> > > &A, int i, int j){
		bool Changed = false;
		if( A[i][j].size() == 1) return false;
		if( A[i][j].size() == 0) return false;
		int n=A.size();

		vector<int> t;
		for(int k = 0; k< A[i][j].size(); k++){
			int m = A[i][j][k];
			bool found = false;
			bool Unique = true;

			//check row
			for(int q=0;q<n;q++){
				if( A[q][j].size() != 1) continue;
				if( A[q][j][0] == m){
					found = true;
					Changed = true;
					break;
				}
			}
			if(found) continue;

			//check col
			for(int q=0;q<n;q++){
				if( A[i][q].size() != 1) continue;
				if( A[i][q][0] == m){
					found = true;
					Changed = true;
					break;
				}
			}
			if(found) continue;

			//check square
			for(int q=0;q<3;q++){
				for(int p=0;p<3;p++){
					if( A[3*(i/3) + q][3*(j/3) + p].size() != 1) continue;
					if( A[3*(i/3) + q][3*(j/3) + p][0] == m){
						found = true;
						Changed = true;
						break;
					}
				}
			}
			if(found) continue;
			t.push_back(m);

			//check Unique
			//check row
			/*for(int q=0;q<n;q++){
				if( A[q][j].size() != 1){
					if(find(A[q][j].begin(), A[q][j].end(), m) != A[q][j].end()){
						Unique = false;
						break;
					}
				}
			}

			if(Unique){//if Unique, set the value directlys	
				t.clear();
				t.push_back(m);
				Changed = true;
				break;
			}

			//check col
			for(int q=0;q<n;q++){
				if( A[i][q].size() != 1){
					if(find(A[i][q].begin(), A[i][q].end(), m) != A[i][q].end()){
						Unique = false;
						break;
					}
				}
			}
			if(Unique){//if Unique, set the value directlys	
				t.clear();
				t.push_back(m);
				Changed = true;
				break;
			}

			//check square
			for(int q=0;q<3;q++){
				for(int p=0;p<3;p++){
					if( A[3*(i/3) + q][3*(j/3) + p].size() != 1){
						if(find( A[3*(i/3) + q][3*(j/3) + p].begin(),  A[3*(i/3) + q][3*(j/3) + p].end(), m) !=  A[3*(i/3) + q][3*(j/3) + p].end()){
							Unique = false;
							break;
						}
					}
				}
			}
			if(Unique){//if Unique, set the value directlys	
				t.clear();
				t.push_back(m);
				Changed = true;
				break;
			}*/
		}

		A[i][j] = t;
		
		return Changed;
	}

    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = board.size();

		vector<vector< vector<int> > > A;
		A.resize(n);

		for(int i=0;i<n;i++){
			A[i].resize(n);
		}

		vector<int> T;
		for(int i=0;i<n;i++){
			T.push_back(i+1);
		}

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(board[i][j] != '.'){
					A[i][j].push_back(board[i][j]-'0');
				}else{
					vector<int> t(T.begin(), T.end());
					A[i][j] = t;
				}
			}
		}

		bool solved = SolveSudokuRec(A);

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(A[i][j].size() == 0) continue;
				board[i][j] = A[i][j][0] + '0';
			}
		}
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
	
	s.solveSudoku(A);

	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout << A[i][j];
		}
		cout << endl;
	}

	system("pause");
}
