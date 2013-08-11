/*Trapping Rain WaterMar 10 '123546 / 8836
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.



The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Author: Wencan Luo
Language: C++
Date: 08/06/2013
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
#include<stack>
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
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	if(n==0) return 0;
		int area = 0;

		vector<int> L;
        vector<int> R;
        L.resize(n,0);
        R.resize(n,0);

        int m = 0;
		for(int i=0;i<n;i++){
            m = max(m, A[i]);
            L[i] = m;
		}

        m = 0;
        for(int i=n-1;i>=0;i--){
            m = max(m, A[i]);
            R[i] = m;
    	}
        
        for(int i=0;i<n;i++){
            area += max(min(L[i], R[i]) - A[i], 0);
        }
        
        return area;
    }
};

void main(){
    Solution s;

	//int a[] = {1,5,3,3,2,0,1,1,3,4,6,8};
	int a[] = {4,2,3};
	cout << s.trap(a, sizeof(a)/sizeof(a[0]));
	
	system("pause");
}
