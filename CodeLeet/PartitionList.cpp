/*Partition List Apr 30 '123488 / 10672
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

Author: Wencan Luo
Language: C++
Date: 07/18/2013
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

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL) return NULL;

		ListNode *lowhead, *highhead;

		//find low head
		ListNode *p = head;
		while(p != NULL){
			if(p->val < x) break;
			p = p->next;
		}
		if(p == NULL) return head;
		lowhead = p;

		//find high head
		p = head;
		while(p != NULL){
			if(p->val >= x) break;
			p = p->next;
		}
		if(p == NULL) return head;
		highhead = p;

		ListNode *q = lowhead;
		ListNode *r = highhead;

		p = head;
		while(p != NULL){
			if(p == lowhead){
				p = p->next;
				continue;
			}

			if(p == highhead){
				p = p->next;
				continue;
			}

			if(p->val < x){
				q->next = p;
				q = q->next;
			}else{
				r->next = p;
				r = r->next;
			}
			p = p->next;
		}

		r->next = NULL;
		q->next = highhead;

		return lowhead;
    }
};

void main(){
	Solution s;

	ListNode a(1);
	ListNode b(4);
	ListNode c(3);
	ListNode d(2);
	ListNode e(5);
	ListNode f(2);

	//a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;

	ListNode *p = s.partition(&a, 0);

	while(p){
		cout << p->val << ",";
		p = p->next;
	}
	cout << endl;

	system("pause");
}
