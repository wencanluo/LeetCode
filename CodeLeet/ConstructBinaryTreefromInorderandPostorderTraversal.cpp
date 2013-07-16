/*Construct Binary Tree from Inorder and Postorder TraversalSep 30 '122906 / 8158
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
    }
};

void main(){
	Solution s;

	int a[] = {1,2};
	vector<int> v(a, a + sizeof(a)/sizeof(a[0]));
	
	//TreeNode* r = s.sortedArrayToBST(v);
	//TreeNode* r = s.sortedListToBST(L);

	//cout << r->val << endl;
	//cout << r->left << endl;
	//cout << r->right << endl;

	system("pause");
}
