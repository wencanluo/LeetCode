/*Jump GameMar 25 '125618 / 13186
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

Author: Wencan Luo
Language: C++
Date: 08/01/2013
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

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0) return true;
        
        int k=0;
        while(1){
            if(k>=n-1) return true;
            
            int next = A[k];
            if(next == 0) break;
                        
            int nextMax = 0;
            for(int i=k+1;i<=next+k && i<n;i++){
                nextMax = max(nextMax, A[i]+i);
            }
            k = nextMax;
        }
        
        return false;
    }
};

void main(){
	Solution s;

	system("pause");
}
