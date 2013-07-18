/*Symmetric Tree Sep 24 '124840 / 10056
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:

    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

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
	bool isSymmetricRec(TreeNode *left, TreeNode *right) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(left == NULL && right == NULL) return true;
		if(left == NULL) return false;
		if(right == NULL) return false;

		if(left->val != right->val) return false;

		if(!isSymmetricRec(left->left, right->right)) return false;
		if(!isSymmetricRec(left->right, right->left)) return false;

		return true;
    }

    bool isSymmetricR(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( NULL == root ) return true;

		return isSymmetricRec(root->left, root->right);
    }

	bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( NULL == root ) return true;
		if(root->left == NULL && root->right == NULL) return true;
		if(root->left == NULL) return false;
		if(root->right == NULL) return false;

		queue<TreeNode*> Q1, Q2;
		Q1.push(root->left);
		Q2.push(root->right);

		while(!Q1.empty()){
			TreeNode* q1 = Q1.front();
			Q1.pop();

			if(Q2.empty()) return false;
			TreeNode* q2 = Q2.front();
			Q2.pop();

			if(q1->val != q2->val) return false;

			if(q1->left == NULL && q2->right != NULL) return false;
			if(q1->right == NULL && q2->left != NULL) return false;

			if(q1->left != NULL){
				Q1.push(q1->left);
			}

			if(q2->right != NULL){
				Q2.push(q2->right);
			}

			if(q1->right != NULL){
				Q1.push(q1->right);
			}

			if(q2->left != NULL){
				Q2.push(q2->left);
			}
		}

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
