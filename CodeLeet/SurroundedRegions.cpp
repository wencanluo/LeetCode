/*Surrounded Regions
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region .

For example,

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

Author: Wencan Luo
Language: C++
Date: 06/04/2013
*/

#include<iostream>
using namespace std;

#include<vector>
#include<string>
#include<algorithm>
#include<queue>

class Solution {
public:
	void PrintMatrix(vector<vector<char>> A){
		for(int i=0;i<A.size();i++){
			for(int j=0;j<A.size();j++){
				cout << A[i][j];
			}
			cout << endl;
		}
	}

	void CheckFirstRound(vector<vector<char>> &board, queue<pair<int, int>> &Q){
		int n = board.size();
		if(n==0) return;
		int m = board[0].size();

		for(int i=0, j=0;j<m;j++){
			if(board[i][j] == 'O'){
				Q.push(make_pair(i,j));
			}
		}

		for(int i=n-1, j=0;j<m;j++){
			if(board[i][j] == 'O'){
				Q.push(make_pair(i,j));
			}
		}

		for(int i=1, j=0;i<n-1;i++){
			if(board[i][j] == 'O'){
				Q.push(make_pair(i,j));
			}
		}

		for(int i=1, j=m-1;i<n-1;i++){
			if(board[i][j] == 'O'){
				Q.push(make_pair(i,j));
			}
		}
	}

	void CheckBoard(vector<vector<char>> &board, int i, int j, queue<pair<int, int>> &Q){
		int n = board.size();
		if(n==0) return;
		int m = board[0].size();

		if(i>0 && board[i-1][j] == 'O'){
			Q.push(make_pair(i-1,j));
		}

		if(j>0 && board[i][j-1] == 'O'){
			Q.push(make_pair(i,j-1));
		}

		if(i+1<n && board[i+1][j] == 'O'){
			Q.push(make_pair(i+1,j));
		}

		if(j+1<m && board[i][j+1] == 'O'){
			Q.push(make_pair(i,j+1));
		}
	}

    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int n = board.size();
		if(n==0) return;

		int m = board[0].size();

		queue<pair<int, int>> Q;

		CheckFirstRound(board, Q);

		while(!Q.empty()){
			pair<int, int> p = Q.front();
			Q.pop();

			//mark it
			CheckBoard(board, p.first, p.second, Q);

			board[p.first][p.second] = 'Z';

			//cout << p.first << "," << p.second << endl;
		}

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(board[i][j] =='O'){
					board[i][j] = 'X';
				}else if(board[i][j] =='Z'){
					board[i][j] = 'O';
				}
			}
		}
		//PrintMatrix(board);
    }
};


void main(){
	Solution s;
	
	string A[] = {"OXXOX","XOOXO","XOXOX","OXOOO","XXOXO"};
	vector<vector<char>> board;
	int n = sizeof(A)/sizeof(A[0]);

	for(int i=0;i<n;i++){
		vector<char> tmp(&A[i][0], &A[i][0]+n);
		board.push_back(tmp);
	}

	s.solve(board);

	system("pause");
}
