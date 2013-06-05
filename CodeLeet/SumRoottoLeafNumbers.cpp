/*Sum Root to Leaf NumbersFeb 193538 / 9970
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

Author: Wencan Luo
Language: C++
Date: 06/05/2013
*/

#include<iostream>
using namespace std;

#include<vector>
#include<string>
#include<algorithm>

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void BFSBinaryTree(TreeNode *root, int &sum){
		if(root->left == NULL && root->right == NULL){//leave node
			sum += root->val;
			return;
		}

		if( root->left != NULL){
			root->left->val += root->val * 10;
			BFSBinaryTree(root->left, sum);
		}

		if(root->right != NULL){
			root->right->val += root->val * 10;
			BFSBinaryTree(root->right, sum);
		}
	}

    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(root == NULL) return 0;

		int sum = 0;
		BFSBinaryTree(root, sum);
        return sum;
    }
};


void main(){
	Solution s;
	
	TreeNode *root  = new TreeNode(1);
	TreeNode *left  = new TreeNode(2);
	left->left = NULL;
	left->right = NULL;

	TreeNode *right  = new TreeNode(3);
	right->left = NULL;
	right->right = NULL;

	root->left = left;
	root->right = right;

	cout << s.sumNumbers(root);

	//system("pause");
}
