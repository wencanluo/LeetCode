/*Merge k Sorted ListsFeb 14 '125371 / 18133
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

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

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int n = lists.size();
		if(n == 0) return NULL;
		if(n==1) return lists[0];

		ListNode *head = lists[0];
        for(int i=1;i<n;i++){
			head = mergeTwoLists(head, lists[i]);
		}
		return head;
    }
};


