/*
Intersection of Two Linked Lists Total Accepted: 2302 Total Submissions: 7941 My Submissions Question Solution 
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.


Author: Wencan Luo
Language: C++
Date: 11/30/2014
*/
#include<isotream>
#include<stdlib>
#include<cstddef>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    
    int getLength(ListNode *head){
        int length = 0;
        
        while(head != NULL){
            length++;
            head = head->next;
        }
        return length;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        //get the length
        int lengthA = getLength(headA);
        int lengthB = getLength(headB);
        
        //extreme case
        if(lengthA == 0 || lengthB == 0) return NULL;
        
        //go to the same position of the longer one and compare them one by one
        int i=lengthA;
        int j=lengthB;
        
        while(j > i){
            headB = headB->next;
            j--;
        }
        
        while(i > j){
            headA = headA->next;
            i--;
        }
        
        //i==j
        while(i>0){
            if(headA==headB) return headA;
            i--;
        }
        
    	return NULL;
    }
};

int main(){
	Solution s;
	
	cout << "done!" << endl;
	
	return 0;
}
