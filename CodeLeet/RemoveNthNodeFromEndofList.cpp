/*Remove Nth Node From End of ListJan 28 '125786 / 15257
Given a linked list, remove the nth node from the end of list and return its head.
For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

   Note:
Given n will always be valid.
Try to do this in one pass.

Author: Wencan Luo
Language: C++
Date: 08/13/2013
*/

#include<iostream>
using namespace std;
#include<climits>

#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
#include<stack>
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(head == NULL) return NULL;

        ListNode *p = head;
		int k = n;

		while(--k){
			p = p->next;
		}
		if(p == NULL) return head;

		ListNode *r = NULL;
		ListNode *q = head;
		while(p->next){
			r = q;
			q = q->next;
			p = p->next;
		}

		if(r==NULL){//delete the head
			head = q->next;
			delete(q);
		}else{
			r->next = q->next;
			delete(q);
		}
		return head;
    }
};

void main(){
    Solution s;

	ListNode *a = new ListNode(1);
	a = s.removeNthFromEnd(a, 1);

	while(a){
		cout << a->val << endl;
		a = a->next;
	}
    
	system("pause");
}



