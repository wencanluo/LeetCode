/*Binary Tree Traversal (Inorder, Postorder, Preorder) Without Recursive
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


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".


Author: Wencan Luo
Language: C++
Date: 08/31/2012
*/

#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void preorderRecurseVisit(TreeNode *root, vector<int> &visit)
	{
		if(root == NULL) return;

		//visit root
		visit.push_back(root->val);

		//visit Left
		if( root->left != NULL) inorderRecurseVisit(root->left, visit);
		
		//visit right
		if( root->right != NULL) inorderRecurseVisit(root->right, visit);
	}

	void inorderRecurseVisit(TreeNode *root, vector<int> &visit)
	{
		if(root == NULL) return;

		//visit Left
		if( root->left != NULL) inorderRecurseVisit(root->left, visit);

		//visit root
		visit.push_back(root->val);

		//visit right
		if( root->right != NULL) inorderRecurseVisit(root->right, visit);
	}

	void postorderRecurseVisit(TreeNode *root, vector<int> &visit)
	{
		if(root == NULL) return;

		//visit Left
		if( root->left != NULL) inorderRecurseVisit(root->left, visit);
		
		//visit right
		if( root->right != NULL) inorderRecurseVisit(root->right, visit);

		//visit root
		visit.push_back(root->val);
	}

	void preorderVisit(TreeNode *root, vector<int> &visit)
	{
		if(root == NULL) return;

		stack<TreeNode*> s;
		//map<TreeNode*, int> hash;

		s.push(root);
		while(!s.empty())
		{
			//visit the root
			TreeNode *p = s.top();
			visit.push_back(p->val);
			s.pop();

			//push the children
			if(p -> right != NULL)//push the right first
				s.push(p->right);
			if(p -> left != NULL)
				s.push(p->left);
			
		}
	}

	void inorderVisit(TreeNode *root, vector<int> &visit)
	{
		if(root == NULL) return;

		stack<TreeNode*> s;
		map<TreeNode*, int> hash;

		s.push(root);
		while(!s.empty())
		{
			//locate to the leftmost unvisited one
			TreeNode *p = s.top();
			while(p->left != NULL && hash[p->left] == NULL)
			{
				p = p -> left;
				s.push(p);
			}

			//visit the leftmost unvisited one and mark it
			p = s.top();
			visit.push_back(p->val);
			hash[p] = 1;
			s.pop();

			//push the right child
			if(p -> right != NULL)
				s.push(p->right);
		}
	}

	void postorderVisit(TreeNode *root, vector<int> &visit)
	{
		if(root == NULL) return;

		stack<TreeNode*> s;
		map<TreeNode*, int> hash;

		s.push(root);
		while(!s.empty())
		{
			//get the root and check the left and right
			TreeNode *p = s.top();
			if((p->left == NULL || hash[p->left] != NULL) && (p->right == NULL || hash[p->right] != NULL))//have visted the left and right
			{
				visit.push_back(p->val);
				hash[p] = 1;
				s.pop();
			}
			else
			{
				if(p->right != NULL && hash[p->right] == NULL)
					s.push(p->right);
				if(p->left != NULL && hash[p->left] == NULL)
					s.push(p->left);
			}
		}
	}

    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<int> res;

		//inorderRecurseVisit(root, res);
		//preorderVisit(root, res);
		postorderVisit(root, res);

		return res;
    }

	TreeNode* OJ2BinarTree(vector<int> oj)
	{
		TreeNode *root = NULL;
		if(oj.size() == 0) return root;

		queue<TreeNode*> q;
		root = new TreeNode(oj[0]);
		q.push(root);

		for(vector<int>::iterator it = oj.begin()+1; it < oj.end(); it = it +2)
		{
			TreeNode *p = q.back();
			q.pop();

			if(*it != '#') //left child
			{
				p->left = new TreeNode(*it);
				q.push(p->left);
			}

			if(*(it+1) != '#')//left child
			{
				p->right = new TreeNode(*(it+1));
				q.push(p->right);
			}
		}

		return root;
	}
};

void main()
{
	int a[] = {1,2,3,'#','#',4,'#','#',5};
	vector<int> input(a, a + sizeof(a)/sizeof(int));
	Solution s;

	TreeNode *t = s.OJ2BinarTree(input);
	
	vector<int> res = s.inorderTraversal(t);

	for(vector<int>::iterator it = res.begin(); it< res.end(); it++)
	{
		cout << *it << ", ";
	}

	system("pause");
}