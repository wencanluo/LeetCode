/*Same TreeSep 3 '124395 / 6839
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

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

   bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(p == NULL && q == NULL) return true;
		if(p == NULL) return false;
		if(q == NULL) return false;

		if(p->val != q->val) return false;

		if(!isSameTree(p->left, q->left)) return false;
		if(!isSameTree(p->right, q->right)) return false;

		return true;
    }
};

void main(){
	Solution s;
	
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(2);
	TreeNode d(3);
	TreeNode e(3);
	a.left = &b;
	b.right = &d;

	a.right = &c;
	c.right = &e;
	
	cout << s.isSymmetric(&a);

	system("pause");
}
