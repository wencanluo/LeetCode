/*Longest Common PrefixJan 17 '125821 / 16194
Write a function to find the longest common prefix string amongst an array of strings.

Author: Wencan Luo
Language: C++
Date: 08/14/2013
*/

#include<iostream>
using namespace std;
#include<climits>

#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
#include<stack>
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
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string r = "";

		int n=strs.size();
		if(n == 0) return r;
		if(n == 1) return strs[0];
		for(int i=0;i<strs[0].size();i++){
			char c = strs[0][i];

			bool found = true;
			for(int j=1;j<n;j++){
				if(strs[j].size() < i+1 || strs[j][i] != c){
					found = false;
					break;
				}
			}

			if(!found) break;
			r += c;
		}

		return r;
    }
};

void main(){
    Solution s;

	system("pause");
}



