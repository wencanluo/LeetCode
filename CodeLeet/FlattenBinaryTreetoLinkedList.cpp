/*Flatten Binary Tree to Linked List Oct 14 '124315 / 12810
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

Author: Wencan Luo
Language: C++
Date: 07/05/2013
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


//Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode *getRigthMost(TreeNode *root){
		if(root == NULL) return NULL;
		TreeNode *p, *q;
		p = root;
		q = p->right;

		while(q!= NULL){
			p = q;
			q = q->right;
		}
		return p;
	}

    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if(root == NULL) return;

        flatten(root->left);
		flatten(root->right);

		//visit root
		if(root->left == NULL) return;

		TreeNode *left = getRigthMost(root->left);
		if(left != NULL){
			left->right = root->right;
			root->right = root->left;
			root->left = NULL;
		}
    }
};

void main(){

	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);

	a.left = &b;
	b.left= &c;

	Solution s;	

	s.flatten(&a);

	cout << a.val << endl;
	cout << a.right->val << endl;
	cout << a.right->right->val << endl;
	
	system("pause");
}
