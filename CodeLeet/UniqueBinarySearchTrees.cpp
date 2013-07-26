/*Unique Binary Search Trees Aug 27 '123518 / 6614
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

Unique Binary Search Trees II Aug 27 '122317 / 6957
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

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

// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
	int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<=0) return 0;

		vector<int> A;
		A.resize(n+1,0);
		A[0] = 1;
		A[1] = 1;

		for(int i=2;i<=n;i++){
			A[i] = 0;
			for(int j=0; j<i; j++){
				A[i] += A[j] * A[i-j-1];
			}
		}

		return A[n];
    }

	vector<TreeNode *> generateTrees(int begin, int end){
		if(end<=begin) {
			vector<TreeNode *> tmp;
			tmp.push_back(NULL);
			return tmp;
		}
		
		if(end == begin + 1){
			vector<TreeNode *> tmp;
			tmp.push_back(new TreeNode(begin));
			return tmp;
		}

		vector<TreeNode *> res;
		for(int i=begin;i<end;i++){
			vector<TreeNode *> left = generateTrees(begin, i);
			vector<TreeNode *> right = generateTrees(i+1, end);

			for(int j=0; j<left.size(); j++){
				for(int k=0;k<right.size();k++){
					TreeNode *root = new TreeNode(i);
					root->left = left[j];
					root->right = right[k];
					res.push_back(root);
				}
			}
		}

		return res;
	}

	vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		return generateTrees(1,n+1);
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

	cout << s.generateTrees(3).size();
	system("pause");
}
