/*Path Sum Oct 14 '124006 / 9340
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

Path Sum II Oct 14 '123751 / 10572
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
]

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
	 void pathSumRec(TreeNode *root, int sum, vector<int> path, vector<vector<int> > &res) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) return;

		path.push_back(root->val);
		if(root->left == NULL && root->right == NULL){
			if(root->val == sum){
				res.push_back(path);
			}
		}

		if(root->left != NULL){
			pathSumRec(root->left, sum - root->val, path, res);
		}

		if(root->right != NULL){
			pathSumRec(root->right, sum - root->val, path, res);
		}
     }

	 vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
		vector<int> path;

		pathSumRec(root, sum, path, res);

		return res;
    }

    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) return false;

		if(root->left == NULL && root->right == NULL){
			if(root->val == sum) return true;
		}

		if(root->left != NULL){
			if(hasPathSum(root->left, sum - root->val)){
				return true;
			}
		}

		if(root->right != NULL){
			if(hasPathSum(root->right, sum - root->val)){
				return true;
			}
		}

		return false;
    }
};

void main(){

	TreeNode a(0);
	TreeNode b(1);
	TreeNode c(1);

	a.left = &b;
	a.right= &c;

	Solution s;	

	vector< vector<int> > res = s.pathSum(&a, 1);

	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++){
			cout << res[i][j] << ",";
		}
		cout << endl;
	}

	system("pause");
}
