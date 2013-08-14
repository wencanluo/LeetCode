/*Generate ParenthesesFeb 13 '125572 / 13200
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

Author: Wencan Luo
Language: C++
Date: 08/13/2013
*/

#include<iostream>
using namespace std;
#include<climits>

#include<vector>
#include<string>
#include<algorithm>
#include<sstream>

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
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<string> r;
		if(n==0){
			r.push_back("");
			return r;
		}

        if(n==1){
			r.push_back("()");
			return r;
		}

		for(int k=0;k<n;k++){
			vector<string> left = generateParenthesis(k);
			vector<string> right = generateParenthesis(n-k-1);
			
			for(int i=0;i<left.size();i++){
				for(int j=0;j<right.size();j++){
					r.push_back(left[i] + "(" + right[j] + ")");
				}
			}
		}
		return r;
    }
};

void main(){
    Solution s;
    
	system("pause");
}



