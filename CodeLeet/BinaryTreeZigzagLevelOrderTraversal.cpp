/*Binary Tree Zigzag Level Order Traversal Sep 29 '122960 / 8162
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]
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
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
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

		for(int i=0;i<res.size();i++){
			if(i%2 == 1){ // reverse
				vector<int> tmp;

				for(int j=res[i].size() - 1; j >= 0; j--){
					tmp.push_back(res[i][j]);
				}

				res[i] = tmp;
			}
		}

		return res;
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

	//cout << s.minimumTotal(B);
	system("pause");
}
