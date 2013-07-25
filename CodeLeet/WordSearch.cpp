/*Word Search Apr 18 '124672 / 15082
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

Author: Wencan Luo
Language: C++
Date: 07/25/2013
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

	bool exist_rec(vector<vector<char> > &board, int x, int y, vector<vector<bool> > &A, string word){
		//find the first one
		if(word.size() == 0) return true;

		int n = board.size();
		if(n <=0) return false;
		int m = board[0].size();

		int i=x+1, j=y;
		if(i < n && !A[i][j] && (board[i][j] == word[0])){
			A[i][j] = true;
			bool found = exist_rec(board, i, j, A, word.substr(1,word.size()-1));
			if(found) return true;
			A[i][j] = false;
		}

		i=x-1, j=y;
		if(i >= 0 && !A[i][j] && (board[i][j] == word[0])){
			A[i][j] = true;
			bool found = exist_rec(board, i, j, A, word.substr(1,word.size()-1));
			if(found) return true;
			A[i][j] = false;
		}

		i=x, j=y+1;
		if(j < m && !A[i][j] && (board[i][j] == word[0])){
			A[i][j] = true;
			bool found = exist_rec(board, i, j, A, word.substr(1,word.size()-1));
			if(found) return true;
			A[i][j] = false;
		}

		i=x, j=y-1;
		if(j >= 0 && !A[i][j] && (board[i][j] == word[0])){
			A[i][j] = true;
			bool found = exist_rec(board, i, j, A, word.substr(1,word.size()-1));
			if(found) return true;
			A[i][j] = false;
		}

		return false;
	}

    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(word.size() == 0) return true;

		int n = board.size();
		if(n <=0) return false;
		int m = board[0].size();

		vector<vector<bool> > A;
		A.resize(n);
		for(int i=0;i<n;i++){
			A[i].resize(m, false);
		}

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(!A[i][j] && (board[i][j] == word[0])){
					A[i][j] = true;
					bool found = exist_rec(board, i, j, A, word.substr(1,word.size()-1));
					if(found) return true;
					A[i][j] = false;
				}
			}
		}

		return false;
    }
};

void main(){
	Solution s;
	
	char a[] = "ab";
	vector<char> va;
	va.push_back('a');
	va.push_back('b');

	vector<vector<char> > vva;
	vva.push_back(va);

	cout << s.exist(vva, "ba");

	system("pause");
}
