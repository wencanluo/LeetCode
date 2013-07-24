/*Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.


Remove Duplicates from Sorted List IIApr 22 '123822 / 11907
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

Author: Wencan Luo
Language: C++
Date: 07/23/2013
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
    ListNode *deleteDuplicatesI(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (NULL == head) return NULL;
        
        ListNode *p, *q;
        p = head;
        q = p->next;
        
        while(q != NULL){
            if(p->val == q->val){
                //remove q
                p->next = q->next;
                delete(q);
                q = p->next;
            }else{
                p = q;
                q = q->next;
            }
        }
        
        return head;
    }
    
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (NULL == head) return NULL;
        
        ListNode *p, *q, *r;
        p = NULL;
        q = head;
        r = p->next;
        
        bool flag = false;
        
        while(r != NULL){
            if(q->val == r->val){
                //remove r
                q->next = r->next;
                delete(r);
                r = q->next;
                flag = true;
            }else{
                if(flag){//delete q
                    if(p == head){
                        p = p->next;
                        delete(p);
                        
                        
                    }else{
                        
                    }
                }
                
                p = q;
                q = q->next;
                flag = false;
            }
        }
        
        return head;
    }
};

int main(){
	Solution s;
    
    return 0;	
}
