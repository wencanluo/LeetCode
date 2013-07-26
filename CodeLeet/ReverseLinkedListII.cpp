/*Reverse Linked List II Jun 27 '123651 / 12649
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 <= m <= n <= length of list.

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
 

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *reverse(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL) return NULL;

		ListNode *p, *q, *r;
		p = NULL;
		q = head;
		r = head->next;

		while(q != NULL){
			q->next = p;

			p = q;
			q = r;
			if(q == NULL) break;
			r = r->next;
		}
		
		return p;
    }

    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if (head == NULL) return NULL;
		if (m==n) return head;

		//travel to m
		ListNode *p = NULL;
		ListNode *q = head;
		ListNode *r = head->next;

		int i=m;
		while( i-- > 1){
			p = q;
			q = r;
			r = r->next;
		}

		ListNode* oldp = p;
		ListNode* oldq = q;

		//travel one more
		p = q;
		q = r;
		r = r->next;

		//reverse until n
		i = m;
		while(q != NULL){
			q->next = p;
			i++;

			p = q;
			q = r;
			if(i == n) break;
			if(q == NULL) break;
			r = r->next;
		}

		oldq->next = q;
		if(oldp != NULL){
			oldp->next = p;			
		}else{
			head = p;
		}

		return head;
    }
};

void main(){
	Solution s;
	
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(2);
	ListNode *c = new ListNode(3);
	a->next = b;
	b->next = c;

	ListNode *p = a;
	while(p){
		cout << p->val << ",";
		p = p->next;
	}
	cout << endl;

	p = s.reverseBetween(a, 2, 3);
	while(p){
		cout << p->val << ",";
		p = p->next;
	}
	cout << endl;
	
	system("pause");
}
