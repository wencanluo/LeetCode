/*Valid ParenthesesJan 30 '125205 / 13591
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

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
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> Q;

		for(int i=0;i<s.size();i++){
			switch(s[i]){
			case '(':
				Q.push(')');
				break;
			case '{':
				Q.push('}');
				break;
			case '[':
				Q.push(']');
				break;
			default:
				if(Q.empty()) return false;
				char c = Q.top();
				Q.pop();
				if(c != s[i]) return false;
				break;
			}
		}

		if(!Q.empty()) return false;

		return true;
    }
};

void main(){
    Solution s;
    
	cout << s.isValid("([]{})") << endl;

	system("pause");
}



