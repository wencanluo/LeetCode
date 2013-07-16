/*Convert Sorted List to Binary Search Tree Oct 3 '123579 / 10038
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

Convert Sorted Array to Binary Search Tree Oct 2 '123625 / 7551
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

Author: Wencan Luo
Language: C++
Date: 07/11/2013
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
	TreeNode *sortedListToBSTRec(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(0 >= n) return NULL;
		if(1 == n) return new TreeNode(head->val);

		//find the mid
		ListNode *p = head;

		int mid = n/2;
		while(mid-- > 0){
			p = p -> next;
		}

		mid = n/2;
		TreeNode *root = new TreeNode(p->val);
		//cout << mid << "\t" << n - mid - 1 << endl;
		root->left = sortedListToBSTRec(head, mid);
		root->right = sortedListToBSTRec(p->next, n - mid - 1);

		//Recursive
		return root;
    }

	TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *p = head;
		int n = 0;

		while(p){
			n++;
			p = p -> next;
		}
		return sortedListToBSTRec(head, n);
    }

    TreeNode *sortedListToBST_OnSpace(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> vec;
		
		ListNode *p = head;
		while(p){
			vec.push_back(p->val);
			p = p -> next;
		}

		return sortedArrayToBST(vec);
    }

	TreeNode *sortedArrayToBSTRec(vector<int> &num, int begin, int end){
		int n = num.size();

		if(n<=0) return NULL;
		if(end <= begin) return NULL;

		int mid = (begin + end)/2;
		if(end == begin + 1) return new TreeNode(num[mid]);

		TreeNode *root = new TreeNode(num[mid]);
		root->val = num[mid];
		root->left = sortedArrayToBSTRec(num, begin, mid);
		root->right = sortedArrayToBSTRec(num, mid+1, end);

		return root;
	}

	TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		
		return sortedArrayToBSTRec(num, 0, num.size());
    }
};

void main(){
	Solution s;

	int a[] = {1,2};
	vector<int> v(a, a + sizeof(a)/sizeof(a[0]));
	//TreeNode* r = s.sortedArrayToBST(v);

	ListNode *L = new ListNode(1);
	L->next = new ListNode(2);
	L->next->next = new ListNode(3);
	
	TreeNode* r = s.sortedListToBST(L);

	cout << r->val << endl;
	cout << r->left << endl;
	cout << r->right << endl;

	system("pause");
}
