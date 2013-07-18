/*Interleaving String Aug 31 '124654 / 16011
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

Author: Wencan Luo
Language: C++
Date: 07/16/2013
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
    bool isInterleave_Recursive(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
		if(s1.size() + s2.size() != s3.size() ) return false;
		if(s3.size() == 0) return true;

		if(s1.size()==0){
			return s2==s3;
		}
		if(s2.size()==0){
			return s1==s3;
		}

		if(s3[0] == s1[0] && s3[0] == s2[0]){
			if(isInterleave_Recursive(s1.substr(1, s1.size() - 1), s2, s3.substr(1,s3.size()-1))) return true;
			if(isInterleave_Recursive(s1, s2.substr(1, s2.size() - 1), s3.substr(1,s3.size()-1))) return true;
		}else if(s3[0] == s1[0]){
			if(isInterleave_Recursive(s1.substr(1, s1.size() - 1), s2, s3.substr(1,s3.size()-1))) return true;
		}else if(s3[0] == s2[0]){
			if(isInterleave_Recursive(s1, s2.substr(1, s2.size() - 1), s3.substr(1,s3.size()-1))) return true;
		}

		return false;
    }

	bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(s1.size() + s2.size() != s3.size() ) return false;
		if(s3.size() == 0) return true;

		if(s1.size()==0){
			return s2==s3;
		}
		if(s2.size()==0){
			return s1==s3;
		}

		int m = s1.size();
		int n = s2.size();
		vector< vector<bool> > A;
		A.resize(m+1);

		for(int i=0;i<=m;i++){
			A[i].resize(n+1, false);
		}
		A[0][0] = true;
		
		//initial
		for(int i=0;i<m;i++){
			if(s1[i] != s3[i]) break;
			A[i+1][0] = true;
		}

		for(int j=0;j<n;j++){
			if(s2[j] != s3[j])break;
			A[0][j+1] = true;
		}

		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(s3[i+j+1] == s1[i]){
					A[i+1][j+1] = A[i+1][j+1] | A[i][j+1];
				}

				if(s3[i+j+1] == s2[j]){
					A[i+1][j+1] = A[i+1][j+1] | A[i+1][j];
				}
			}
		}

		return A[m][n];
    }
};

void main(){
	Solution s;

	//cout << s.isInterleave("a","","a");
	cout << s.isInterleave("aabcc","dbbca","aadbbcbcac");
	cout << s.isInterleave("aabcc","dbbca","aadbbbaccc");

	system("pause");
}
