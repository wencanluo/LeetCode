/*Jump Game II Mar 17 '125817 / 16154
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Author: Wencan Luo
Language: C++
Date: 08/04/2013
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
        
        int maxK = 0;
        for(int i=0;i<n && i <= maxK;i++){
            if(maxK < A[i] + i){
                maxK = A[i] + i;
            }
        }
        
        if(maxK >= n-1) return true;       
        return false;
    }
    
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0) return 0;
        
        vector<int> S;
        S.resize(n, 0);
        
        int maxK = 0;
        for(int i=0;i<n && i <= maxK;i++){
            if(maxK < A[i] + i){
                for(int j=maxK+1; j < n && j <= A[i] + i; j++){
                    S[j] = S[i] + 1;
                }
                maxK = A[i] + i;
            }
        }
        
        return S[n-1];
    }
};

void main(){
	Solution s;

    int A[] = {2,3,1,1,4};
    cout << s.jump(A, sizeof(A)/sizeof(A[0]));
    
	system("pause");
}
