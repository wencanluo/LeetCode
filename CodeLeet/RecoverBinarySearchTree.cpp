/*Recover Binary Search Tree

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Your algorithm should run in O(n) complexity.
Author: Wencan Luo
Language: C++
Date: 06/20/2013
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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void InOrderTravel(TreeNode *root, vector<pair<int, TreeNode *> > &vec){
		if(root == NULL) return;
		
		if(root->left != NULL) InOrderTravel(root->left, vec);
		vec.push_back(make_pair(root->val, root));
		if(root->right != NULL) InOrderTravel(root->right, vec);

	}

	void FindLeft(TreeNode *root, TreeNode **lastone, TreeNode **left){
		if(root == NULL) return;
		
		if(root->left != NULL) FindLeft(root->left, lastone, left);
		
		if(*lastone != NULL){
			if(root->val < (*lastone)->val){
				*left = *lastone;
				return;
			}		
		}
		*lastone = root;

		if(root->right != NULL) FindLeft(root->right, lastone, left);
	}

	void FindRight(TreeNode *root, TreeNode **lastone, TreeNode **right){
		if(root == NULL) return;
		
		if(root->right != NULL) FindRight(root->right, lastone, right);
		
		if(*lastone != NULL){
			if(root->val > (*lastone)->val){
				*right = *lastone;
				return;
			}		
		}
		*lastone = root;
		
		if(root->left != NULL) FindRight(root->left, lastone, right);
	}

	void recoverTree(TreeNode *root) {
		TreeNode *left = NULL;
		TreeNode *right = NULL;
		TreeNode *lastone = NULL;
		FindLeft(root, &lastone, &left);
		lastone = NULL;
		FindRight(root, &lastone, &right);

		if(left == NULL || right == NULL) return;

		int tmp;
		tmp = left->val;
		left->val = right->val;
		right->val = tmp;
	}

    void recoverTree2(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< pair<int, TreeNode *> > vec;

		InOrderTravel(root, vec);
		
		if(vec.size() < 2) return;

		int left = -1;
		int right = -1;

		for(int i=0;i<vec.size()-1;i++){
			if (vec[i].first > vec[i+1].first) {
				left = i;
				break;
			}
		}

		for(int i=vec.size()-1;i>0;i--){
			if (vec[i].first < vec[i-1].first) {
				right = i;
				break;
			}
		}
		
		//swap
		if(left == -1 || right == -1) return;

		int tmp;
		tmp = vec[left].first;
		vec[left].second->val = vec[right].first;
		vec[right].second->val = tmp;
    }
};

void main(){
	TreeNode root(2);
	TreeNode left(3);
	TreeNode right(4);
	TreeNode node(1);

	root.left = &left;
	root.right = &right;
	right.left = &node;

	Solution s;

	s.recoverTree(&root);
}
