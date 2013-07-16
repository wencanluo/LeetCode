/*Binary Tree Level Order Traversal Sep 29 '123923 / 9989
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Binary Tree Level Order Traversal II Oct 1 '122933 / 6702
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:

[
  [15,7]
  [9,20],
  [3],
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

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
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > tmp = levelOrder(root);
		vector<vector<int> > res;

		//reverse
		for(int i=tmp.size()-1;i>=0; i--){
			res.push_back(tmp[i]);
		}

		return res;
    }

    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
		if(NULL == root) return res;

		int level = 0;
		queue<TreeNode *> Q;
		queue<TreeNode *> Q2;

		Q.push(root);
		while(!Q.empty()){
			//extend Q to Q2 (one more level)
			vector<int> tmp;
			while(!Q.empty()){
				TreeNode *top = Q.front();
				Q.pop();
				tmp.push_back(top->val);

				if(top->left != NULL) Q2.push(top->left);
				if(top->right != NULL) Q2.push(top->right);
			}
			res.push_back(tmp);

			//copy Q2 to Q
			while(!Q2.empty()){
				TreeNode *top = Q2.front();
				Q2.pop();
				Q.push(top);
			}
		}

		return res;
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
