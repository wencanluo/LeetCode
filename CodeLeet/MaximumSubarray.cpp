/*Maximum Subarray Mar 21 '124484 / 9520
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

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
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<=0) return 0;
        
        //first the first positive one
        int minV = A[0];
        
        int k=0;
        while(k<n){
            if(A[k] > 0) break;
            if(A[k] < minV) minV = A[k];
            k++;
        }
        
        if(k>=n){
            return minV;//return the minimal one
        }
        
        minV = A[k];
        int sum = minV;
        while(k<n){
            sum += A[k];
            if(sum > minV){
                
            }
        }
    }
};

void main(){
	Solution s;

	system("pause");
}
