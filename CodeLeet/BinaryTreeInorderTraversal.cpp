/*Binary Tree Inorder TraversalAug 27 '124974 / 11382
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

Author: Wencan Luo
Language: C++
Date: 07/17/2013
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
#include<stack>

// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
	 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> A;

		if(root == NULL) return A;

		stack<TreeNode *> S;

		//find the leftmost one
		TreeNode *p = root;

		while(p != NULL){
			S.push(p);
			p = p->left;
		}

		while(!S.empty()){
			TreeNode *q = S.top();
			S.pop();
			A.push_back(q->val);

			//push the right ones
			if(q->right != NULL){
				q = q->right;
				while(q != NULL){
					S.push(q);
					q = q->left;
				}
			}	
		}

		return A;
    }
};

void main(){
	Solution s;
	
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	a.left = &b;
	a.right = &c;
	//b.right = &c;

	vector<int> v = s.inorderTraversal(&a);

	for(int i=0;i<v.size();i++){
		cout << v[i] << ",";
	}
	cout << endl;
	system("pause");
}
