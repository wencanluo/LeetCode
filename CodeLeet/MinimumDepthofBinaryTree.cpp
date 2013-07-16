/*Minimum Depth of Binary TreeOct 10 '124654 / 11636
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) return 0;
		
		queue< pair<TreeNode*, int> > Q;
		Q.push( make_pair(root, 1) );

		while(!Q.empty()){
			pair<TreeNode*, int> p = Q.front();
			Q.pop();

			if(p.first->left == NULL && p.first->right == NULL){
				return p.second;
			}

			if(p.first->left != NULL){
				Q.push(make_pair(p.first->left, p.second+1));
			}

			if(p.first->right != NULL){
				Q.push(make_pair(p.first->right, p.second+1));
			}
		}

		return 0;
    }
};

void main(){
	Solution s;
	
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	a.left = &b;
	a.right = &c;

	cout << s.minDepth(&a);
	//cout << s.minimumTotal(B);
	system("pause");
}
