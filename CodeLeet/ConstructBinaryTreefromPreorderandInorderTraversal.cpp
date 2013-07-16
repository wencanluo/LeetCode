/*Construct Binary Tree from Preorder and Inorder TraversalSep 30 '123219 / 9337
Given preorder and inorder traversal of a tree, construct the binary tree.

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
	TreeNode *buildTreeRec(vector<int> &preorder, int p_begin, int p_end, vector<int> &inorder, int in_begin, int in_end) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(in_end <= in_begin) return NULL;
		if( (in_end - in_begin) != (p_end-p_begin)) return NULL;

		int n = in_end - in_begin;
		if( 1 == in_end - in_begin ){
			if(inorder[in_begin] != preorder[p_begin]) return NULL;
			return new TreeNode(inorder[in_begin]);
		}

		int rootValue = preorder[p_begin];
		int mid = -1;
		for(int i=in_begin; i<in_end;i++){
			if(inorder[i] == rootValue){
				mid = i;
				break;
			}
		}

		if(mid == -1) return NULL;

		TreeNode *root = new TreeNode(rootValue);

		root->left = buildTreeRec(preorder, p_begin+1, p_begin+1+mid-in_begin, inorder, in_begin, mid);
		root->right = buildTreeRec(preorder, p_begin+1+mid-in_begin, p_end, inorder, mid+1, in_end);
		return root;
    }

	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return buildTreeRec(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};

void main(){
	Solution s;

	int a[] = {1,2};
	vector<int> va(a, a + sizeof(a)/sizeof(a[0]));
	
	int b[] = {2,1};
	vector<int> vb(b, b + sizeof(b)/sizeof(b[0]));

	TreeNode* r = s.buildTree(va, vb);
	//TreeNode* r = s.sortedListToBST(L);

	cout << r->val << endl;
	cout << r->left << endl;
	cout << r->right << endl;

	system("pause");
}
