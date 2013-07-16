/*Maximum Depth of Binary TreeSep 30 '124321 / 6225
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node

Author: Wencan Luo
Language: C++
Date: 07/15/2013
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

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 //Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(root == NULL) return 0;

		int left = 0, right = 0;

		left = maxDepth(root->left);
		right = maxDepth(root->right);

		return max(left, right) + 1;
    }
};

void main(){
	Solution s;

	system("pause");
}
