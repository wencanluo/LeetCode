/*Rotate ListMar 28 '123926 / 13178
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

Author: Wencan Luo
Language: C++
Date: 07/31/2013
*/

#include<iostream>
using namespace std;
#include<climits>

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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL) return head;
		//if(k==0) return head;

		ListNode *p = head;

		int n = 0;
		while(NULL != p->next){
			n++;
			p = p->next;
		}
		n++;

		ListNode *tail = p;

		int m = n - k%n;
		if(m==n) return head;

		ListNode *q = NULL;
		p = head;
		while(m > 0){
			q = p;
			p = p->next;
			m--;
		}

		q->next = NULL;
		tail->next = head;

		return p;
    }
};

void main(){
	Solution s;

	system("pause");
}
