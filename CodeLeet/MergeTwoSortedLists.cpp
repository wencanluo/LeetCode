/*Merge Two Sorted ListsMar 30 '124830 / 10178
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.ce.

Author: Wencan Luo
Language: C++
Date: 07/29/2013
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
 

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(NULL == l1) return l2;
		if(NULL == l2) return l1;

		ListNode *head = NULL;
        ListNode *p;		
		ListNode *q;
		
		if(l1->val <= l2->val){
			p = l1;
			q = l2;			
		}else{
			q = l1;
			p = l2;
		}

		head = p;
		ListNode *r = NULL;

		while(NULL != p && NULL != q){//merge l2 to l1
			if(p->val <= q->val) {
				r = p;
				p = p->next;
				continue;
			}

			r->next = q;
			q = q->next;

			r->next->next = p;
			r = r->next;
		}

		if(q != NULL){
			r->next = q;
		}

		return head;
    }
};

void main(){
	Solution s;
	
	ListNode *a = new ListNode(1);
	a->next = new ListNode(8);
	ListNode *b = new ListNode(2);
	b->next = new ListNode(7);

	ListNode *c = s.mergeTwoLists(a,b);
	while(c){
		cout << c->val << ",";
		c = c->next;
	}
	cout << endl;
	system("pause");
}
