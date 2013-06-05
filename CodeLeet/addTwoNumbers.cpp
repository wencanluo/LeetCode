/*
Add Two Numbers
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Author: Wencan Luo
Language: C++
Date: 08/30/2012
*/
#include<iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *res = NULL;
	
		//add one by one
		ListNode *p1=l1, *p2=l2, *p;

		int flag = 0;
		while(p1 != NULL && p2 != NULL)
		{
			int sum = p1->val + p2->val + flag;
			if(res == NULL)//first time
			{
				if(sum >= 10)
				{
					res = new ListNode(sum - 10);
					flag = 1;
				}
				else
				{
					res = new ListNode(sum);
					flag = 0;
				}
				
				p = res;
			}
			else
			{
				if(sum >= 10)
				{
					p->next = new ListNode(sum - 10);
					flag = 1;
				}
				else
				{
					p->next = new ListNode(sum);
					flag = 0;
				}
				p = p->next;
			}

			p1 = p1->next;
			p2 = p2->next;
		}

		while(p1 != NULL)
		{
			int sum = p1->val + flag;
			if(sum >= 10)
			{
				p->next = new ListNode(sum-10);
				flag = 1;
			}
			else
			{
				p->next = new ListNode(sum);
				flag = 0;
			}
			p = p -> next;
			p1 = p1->next;
		}

		while(p2 != NULL)
		{
			int sum = p2->val + flag;
			if(sum >= 10)
			{
				p->next = new ListNode(sum-10);
				flag = 1;
			}
			else
			{
				p->next = new ListNode(sum);
				flag = 0;
			}
			p = p -> next;
			p2 = p2->next;
		}

		if(flag == 1)
		{
			p->next = new ListNode(1);
		}

		return res;
    }
};

void main()
{
	ListNode *a = new ListNode(2);
	ListNode *a2 = new ListNode(4);
	ListNode *a3 = new ListNode(6);
	a->next = a2;
	a2->next = a3;

	ListNode *b = new ListNode(5);
	ListNode *b2 = new ListNode(6);
	ListNode *b3 = new ListNode(4);
	b->next = b2;
	b2->next = b3;

	Solution s;
	ListNode *res = s.addTwoNumbers(a,b);

	ListNode *p = res;
	while(p != NULL)
	{
		cout << p->val << ", ";
		p = p->next;
	}

	system("pause");
}