/*Validate Binary Search TreeAug 31 '124667 / 13380
Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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
	bool isValidBSTRec(TreeNode *root, int *Vmax, int *Vmin){
		if(root == NULL) return true;

		if(root->left == NULL & root->right == NULL){
			*Vmax = *Vmin = root->val;
			return true;
		}

		int Lmax = 0, Lmin = 0;
		int Rmax = 0, Rmin = 0;
		if(root->left != NULL & root->right != NULL){
			bool left = isValidBSTRec(root->left, &Lmax, &Lmin);
			if(!left) return false;

			bool right = isValidBSTRec(root->right, &Rmax, &Rmin);
			if(!right) return false;

			if(root->val <= Lmax || root->val >= Rmin) return false;
			*Vmax = Rmax;
			*Vmin = Lmin;

		}else if(root->left != NULL & root->right == NULL){
			bool left = isValidBSTRec(root->left, &Lmax, &Lmin);
			if(!left) return false;
			if(root->val <= Lmax) return false;
			*Vmax = root->val;
			*Vmin = Lmin;
		}else{//root->left == NULL & root->right != NULL
			bool right = isValidBSTRec(root->right, &Rmax, &Rmin);
			if(!right) return false;
			if(root->val >= Rmin) return false;
			*Vmax = Rmax;
			*Vmin = root->val;
		}

		return true;
	}

    bool isValidBST_Recursive(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int Vmax = 0, Vmin = 0;
        bool valid = isValidBSTRec(root, &Vmax, &Vmin);
		return valid;
    }

	void TreeInorderTravel(TreeNode *root, vector<int> &vec){
		if(root == NULL) return;

		if(root->left != NULL){
			TreeInorderTravel(root->left, vec);
		}

		vec.push_back(root->val);

		if(root->right != NULL){
			TreeInorderTravel(root->right, vec);
		}
	}

	bool TreeInorderTravel_O1Space(TreeNode *root, int &val){
		if(root == NULL) return true;

		if(root->left != NULL){
			bool left = TreeInorderTravel_O1Space(root->left, val);
			if(!left) return false;
		}

		if(root->val <= val) {
			return false;
		}else{
			val = root->val;
		}

		if(root->right != NULL){
			bool right = TreeInorderTravel_O1Space(root->right, val);
			if(!right) return false;
		}

		return true;
	}

	bool isValidBST(TreeNode *root) {//In-order Traveral of a BST should return a sorted array
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(root == NULL) return true;
		int val = INT_MIN;
		return TreeInorderTravel_O1Space(root, val);
    }

	bool isValidBST_OnSpace(TreeNode *root) {//In-order Traveral of a BST should return a sorted array
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(root == NULL) return true;
		vector<int> vec;
		TreeInorderTravel(root, vec);

		for(int i=1;i<vec.size();i++){
			if(vec[i] <= vec[i-1]) return false;
		}
		return true;
    }
};

void main(){
	Solution s;
	
	TreeNode a(0);
	TreeNode b(-1);
	TreeNode c(3);
	//TreeNode d(3);
	//TreeNode e(3);
	a.left = &b;
	//b.right = &d;

	//a.right = &c;
	//c.right = &e;
	
	cout << s.isValidBST(&a);

	system("pause");
}
