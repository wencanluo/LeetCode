/*Reverse Nodes in k-GroupFeb 16 '123953 / 13303
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Author: Wencan Luo
Language: C++
Date: 08/12/2013
*/

#include<iostream>
using namespace std;
#include<climits>

#include<vector>
#include<string>
#include<algorithm>
#include<sstream>

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
	ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return reverseKGroup(head, 2);
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL) return NULL;
		if(k<=1) return head;

		ListNode *p = head;
		int n = k;
		while(--n && p){
			p = p->next;
		}
		if(!p) return head;

		ListNode *newHead = p;
		ListNode *oldtail = NULL;
		while(1){
			ListNode *oldhead = head;

			ListNode *q = head;
			head = p->next;

			ListNode *r = q->next;
			//reverse
			q->next = head;
			while(r != p){
				ListNode *t = r->next;
				r->next = q;
				q = r;
				r = t;
			}
			r->next = q;//last one

			if(oldtail != NULL){
				oldtail->next = r;
			}
			oldtail = oldhead;

			p = head;
			n = k;
			while(--n && p){
				p = p->next;
			}
			if(!p) break;
		}

		return newHead;
    }
};

void main(){
    Solution s;
    
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(2);
	ListNode *c = new ListNode(3);
	ListNode *d = new ListNode(4);
	ListNode *e = new ListNode(5);
	ListNode *f = new ListNode(6);
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = f;

	a = s.reverseKGroup(a, 3);

	while(a){
		cout << a->val << ",";
		a = a->next;
	}
	cout << endl;

	system("pause");
}
