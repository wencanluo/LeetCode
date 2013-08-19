/*Longest Palindromic Substring Nov 11 '118111 / 26433
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

Author: Wencan Luo
Language: C++
Date: 08/19/2013
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
#include<stack>

// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n=s.size();
        if(n<=1) return s;

        int maxCount = 0;
    	int maxBegin = 0, maxEnd = 1;

        for(int i=0;i<n;i++){
            //extension for i, i+1
            int count = 0;
            for(int j=0;i+j+1<n && i-j>=0;j++) {
                if(s[i+j+1] != s[i-j]) break;
                count += 2;
                if(maxCount < count){
					maxCount = count;
					maxBegin = i-j;
					maxEnd = i+j+1;
                }
            }
            
            //extension for i-1, i+1
			count = 1;
            for(int j=1;i+j<n && i-j>=0;j++) {
                if(s[i+j] != s[i-j]) break;
				count += 2;
                if(maxCount < count){
					maxCount = count;
					maxBegin = i-j;
					maxEnd = i+j;
                }
            }
        }

		return s.substr(maxBegin, maxEnd - maxBegin + 1);
    }
};

void main(){
	Solution s;
	
	cout << s.longestPalindrome("ababc") << endl;

	system("pause");
}
