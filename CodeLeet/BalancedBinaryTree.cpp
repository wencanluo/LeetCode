/*Balanced Binary Tree Oct 9 '124862 / 11779
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Author: Wencan Luo
Language: C++
Date: 07/09/2013
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
	bool isBalancedRec_OnSpace(TreeNode *root, map<TreeNode *, pair<int, int>> &M){
		if(root == NULL) return true;

		if(M.find(root) == M.end()){
			M[root] = make_pair(0,0);
		}

		if(root->left == NULL){
			M[root].first = 0;
		}else{
			if(!isBalancedRec_OnSpace(root->left, M)) return false;
		}

		if(root->right == NULL){
			M[root].second = 0;
		}else{
			if(!isBalancedRec_OnSpace(root->right, M)) return false;
		}

		if(root->left != NULL){
			M[root].first = max(M[root->left].first, M[root->left].second) + 1;
		}

		if(root->right != NULL){
			M[root].second = max(M[root->right].first, M[root->right].second) + 1;
		}

		if(M[root].first - M[root].second > 1) return false;
		if(M[root].second - M[root].first > 1) return false;

		return true;
	}

	bool isBalancedRec(TreeNode *root, int *height){
		if(root == NULL){
			*height = 0;
			return true;
		}

		int leftheight = 0, rightheight = 0;
		if(!isBalancedRec(root->left, &leftheight)) return false;
		if(!isBalancedRec(root->right, &rightheight)) return false;

		*height = max(leftheight, rightheight) + 1;
		if(leftheight - rightheight > 1 || rightheight - leftheight > 1) return false;

		return true;
	}

	bool isBalanced(TreeNode *root) {
		// Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) return true;
		int height = 0;
		return isBalancedRec(root, &height);
	}

    bool isBalanced_OnSpace(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) return true;

		map<TreeNode*, pair<int, int> > M;
		return isBalancedRec_OnSpace(root, M);
    }
};

void main(){
	Solution s;
	
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	a.right = &b;
	a.right = &c;
	//b.right = &c;

	cout << s.isBalanced(&a);
	//cout << s.minimumTotal(B);
	system("pause");
}
