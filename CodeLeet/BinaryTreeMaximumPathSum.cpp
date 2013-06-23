/*Binary Tree Maximum Path Sum Nov 8 '123791 / 13737
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.J.

Author: Wencan Luo
Language: C++
Date: 06/21/2013
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
	void maxPathSumRec(TreeNode *root, int &sum, map< TreeNode*, pair<int, int> > &A){
		if(root == NULL) return;

		if(root->left == NULL && root->right == NULL){
			A[root] = make_pair(root->val, root->val);
			if(root->val > sum){
				sum = root->val;
			}
			return;
		}

		//visit left
		if(root->left != NULL){
			maxPathSumRec(root->left, sum, A);
		}

		//visit right
		if(root->right != NULL){
			maxPathSumRec(root->right, sum, A);
		}

		//visit root
		int maxLeft, maxRight;

		if(root->left == NULL){
			maxLeft = root->val;
		}else{
			pair<int, int> pleft = A[root->left];
			maxLeft = max(pleft.first, pleft.second);
			maxLeft = max(maxLeft+root->val, root->val);
		}

		if(root->right == NULL){
			maxRight = root->val;
		}else{
			pair<int, int> pright = A[root->right];
			maxRight = max(pright.first, pright.second);
			maxRight = max(maxRight+root->val, root->val);
		}

		A[root] = make_pair(maxLeft, maxRight);
		if(maxLeft + maxRight - root->val > sum){
			sum = maxLeft + maxRight - root->val;
		}
	}

    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(root == NULL) return 0;

		int sum = root->val;

		map< TreeNode*, pair<int, int> > A;
		maxPathSumRec(root, sum, A);

        return sum;
    }
};

void main(){
	TreeNode first(1);
	TreeNode two(2);
	TreeNode three(3);
	TreeNode four(-1);
	TreeNode five(-1);

	first.left = &two;
	first.right = &three;
	two.left = &four;
	two.right = &five;

	Solution s;

	cout << s.maxPathSum(&first);
}
